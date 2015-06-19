#ifndef PROTON_CPP_CONTAINER_H
#define PROTON_CPP_CONTAINER_H

/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */
#include "proton/export.hpp"
#include "proton/handle.hpp"
#include "proton/acceptor.hpp"
#include "proton/duration.hpp"
#include <proton/reactor.h>
#include <string>

namespace proton {

class dispatch_helper;
class connection;
class Connector;
class acceptor;
class container_impl;
class messaging_handler;
class sender;
class receiver;
class link;
 class handler;

class container : public handle<container_impl>
{
  public:
    PN_CPP_EXTERN container(container_impl *);
    PN_CPP_EXTERN container(const container& c);
    PN_CPP_EXTERN container& operator=(const container& c);
    PN_CPP_EXTERN ~container();

    PN_CPP_EXTERN container();
    PN_CPP_EXTERN container(messaging_handler &mhandler);
    PN_CPP_EXTERN connection connect(std::string &host, handler *h=0);
    PN_CPP_EXTERN void run();
    PN_CPP_EXTERN void start();
    PN_CPP_EXTERN bool process();
    PN_CPP_EXTERN void stop();
    PN_CPP_EXTERN void wakeup();
    PN_CPP_EXTERN bool is_quiesced();
    PN_CPP_EXTERN pn_reactor_t *reactor();
    PN_CPP_EXTERN sender create_sender(connection &connection, std::string &addr, handler *h=0);
    PN_CPP_EXTERN sender create_sender(std::string &url);
    PN_CPP_EXTERN receiver create_receiver(connection &connection, std::string &addr);
    PN_CPP_EXTERN receiver create_receiver(const std::string &url);
    PN_CPP_EXTERN acceptor listen(const std::string &url);
    PN_CPP_EXTERN std::string container_id();
    PN_CPP_EXTERN duration timeout();
    PN_CPP_EXTERN void timeout(duration timeout);
  private:
   friend class private_impl_ref<container>;
};

}

#endif  /*!PROTON_CPP_CONTAINER_H*/