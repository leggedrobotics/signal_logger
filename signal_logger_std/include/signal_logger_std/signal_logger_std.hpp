/*
 * signal_logger_std.hpp
 *
 *  Created on: Sep 23, 2016
 *      Author: Gabriel Hottiger
 */

#pragma once

#define USE_SIGNAL_LOGGER_STD() \
  template<typename ValueType_> \
  void signal_logger::add(const ValueType_ & var, \
                          const std::string & name, \
                          const std::string & group                      = signal_logger::SignalLoggerBase::LOG_ELEMENT_DEFAULT_GROUP_NAME, \
                          const std::string & unit                       = signal_logger::SignalLoggerBase::LOG_ELEMENT_DEFAULT_UNIT, \
                          const std::size_t divider                      = signal_logger::SignalLoggerBase::LOG_ELEMENT_DEFAULT_DIVIDER, \
                          const signal_logger::LogElementAction action   = signal_logger::SignalLoggerBase::LOG_ELEMENT_DEFAULT_ACTION, \
                          const std::size_t bufferSize                   = signal_logger::SignalLoggerBase::LOG_ELEMENT_DEFAULT_BUFFER_SIZE, \
                          const signal_logger::BufferType bufferType     = signal_logger::SignalLoggerBase::LOG_ELEMENT_DEFAULT_BUFFER_TYPE) \
  { \
    dynamic_cast<signal_logger_std::SignalLoggerStd*>(logger.get())->add(&var, name, group, unit, divider, action, bufferSize, bufferType); \
  } \
  FOR_ALL_TYPES(ADD_VAR_TEMPLATE_EXPLICIT_INSTANTIATION);

#include <signal_logger/signal_logger.hpp>
#include <signal_logger_std/SignalLoggerStd.hpp>
#include <signal_logger_std/LogElementStd.hpp>

namespace signal_logger {

void addSignalLoggerStd() {
  logger.reset(new signal_logger_std::SignalLoggerStd() );
}

}
