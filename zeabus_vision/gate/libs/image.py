#!/usr/bin/python3

import numpy as np
import cv2 as cv


class Image:
    def __init__(self, sub_sampling=0.3):
        self.bgr = None
        self.display = None
        self.sub_sampling = sub_sampling

    def get_hsv(self):
        self.hsv = cv.cvtColor(self.bgr, cv.COLOR_BGR2HSV)

    def get_gray(self):
        self.gray = cv.cvtColor(self.bgr, cv.COLOR_BGR2GRAY)

    def callback(self, msg):
        arr = np.fromstring(msg.data, np.uint8)
        self.bgr = cv.resize(cv.imdecode(arr, 1), (0, 0),
                             fx=self.sub_sampling, fy=self.sub_sampling)
        self.display = self.bgr.copy()

    def topic(self, camera):
        if camera == 'front':
            return '/vision/front/image_rect_color/compressed'
        elif camera == 'bottom':
            return '/vision/bottom/image_raw/compressed'

    def renew_display(self):
        self.display = self.bgr.copy()
