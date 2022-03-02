#include "dji_mavlink_adapter.h"
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <ostream>
#include <vector>
#include "mavlink_connector.h"

namespace mavlink_adapter {

    mavlink_connector *mav = nullptr;

    void set_mavlink(std::string _tty, int _port) {
        mav = new mavlink_connector(_tty, _port);
    }

    mavlink_connector *get_mavlink_connector(void) {
        return mav;
    }

    void recv_function() {
        printf("starting recving....\n");
        while (true) {
            if (mav != nullptr)
                mav->recv();
        }
    }

    void loop_callback(long timestamp) {
        mav->fast_send();
        static int k = 0;
        if (k++ % 50 == 0) {
            mav->slow_send();
        }
    }
}
