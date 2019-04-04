// FILE         : base.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019 , APRIL 03

#include    <memory> // use std::shared_ptr followe example code

#include    "rclcpp/rclcpp.hpp"

#include    <iostream>

// MACRO DETAIL FOR DEBUG
//      _SERVICE_CALL_

// warning this template using for service type get formal of srv
//      bool data
//      ---
//      std_msgs/Header header
//      answer_data
// by using template

#ifndef _ZEABUS_SERVICE_GET_TYPE_HPP__
#define _ZEABUS_SERVICE_GET_TYPE_HPP__

namespace zeabus
{

namespace service
{

namespace type_get_01
{

    template< class service_type , class request_type , class response_type , class data_type >
    class Base
    {
        public:
            Base( rclcpp::Node::SharedPtr node )
            {
                this->node = node;
            } // function init class Base

            auto create_service( data_type* data_pointer , std::string topic_name )
            {
                this->data_pointer = data_pointer; // collect pointer to access data
                return this->node->create_service< service_type >( topic_name 
                        , this->function_pointer );
            } // function create_service

        protected:
            rclcpp::Node::SharedPtr node;
            data_type* data_pointer
            // function_pointer to point callback  
            void (*function_pointer)( const std::shared_ptr< rmw_request_id_t > 
                    , const std::shared_ptr< request_type > 
                    , const std::shared_ptr< response_type > ); 

    } // class Base


} // namespace type_get_01

} // namespace service

} // namespace zeabus

#endif // _ZEABUS_SERVICE_GET_TYPE_HPP__