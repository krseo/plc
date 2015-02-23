//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "PlcPhy.h"
#include "PlcSignal_m.h"

Define_Module(PlcPhy);

void PlcPhy::initialize()
{
    EV << "PlcPhy Ready!  \n ";
}

void PlcPhy::handleMessage(cMessage *msg)
{
    if(msg->arrivedOn("InFromMac")){
            EV << "Message From Mac Layer \n ";
            send(msg, "gt$o");
        }
        else if(msg->arrivedOn("gt$i")){
            EV << "Message From PlcBus\n";
            send(msg, "OutToMac");
        }else{
            EV << "Message From ?  Something Wrong\n";
        }
}
