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

#include "PlcMac.h"
#include "PlcFrame_m.h"
#include "PlcSignal_m.h"

Define_Module(PlcMac);

void PlcMac::initialize()
{
    EV << "PlcMac Ready! \n ";
}

void PlcMac::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->arrivedOn("InFromApp")){
        EV << "Message From App Layer \n ";
        //send(msg, "OutToPhy");
        sendDown(msg);
    }
    else if(msg->arrivedOn("InFromPhy")){
        EV << "Message From Phy Layer\n";
        sendUp(msg);
        /*PlcSignal *Signal  = (PlcSignal*) msg;
        PlcFrame *Frame = (PlcFrame*)Signal->decapsulate();
        send(Frame, "OutToApp");*/
    }else{
        EV << "Message From ?  Something Wrong\n";
    }
}

void PlcMac::sendUp(cMessage *msg)
{
    PlcSignal *Signal  = (PlcSignal*) msg;
    PlcFrame *Frame = (PlcFrame*)Signal->decapsulate();
    send(Frame, "OutToApp");
}

void PlcMac::sendDown(cMessage *msg)
{
    PlcFrame *Frame = (PlcFrame*)msg;
    PlcSignal *Signal  = new PlcSignal();
    Signal->encapsulate(Frame);
    send(Signal,"OutToPhy");
   // Signal->
}

