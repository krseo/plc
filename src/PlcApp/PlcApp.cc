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

#include "PlcApp.h"
#include "PlcPkt_m.h"
#include "PlcFrame_m.h"

Define_Module(PlcApp);

void PlcApp::initialize()
{

    std::string AppType = par("Apptype");

    PlcPkt *pkt = new PlcPkt("Head Pkt");
    pkt->setData("Head Data");

    EV << getName() << " PlcApp Type " << AppType << endl;

    if (!strcmp("Head", par("Apptype"))){
        PlcFrame *Frame = new PlcFrame();
        Frame->encapsulate(pkt);
        send(Frame, "OutToMac");
    }
    //send(msg, "OutToMac");

}

void PlcApp::handleMessage(cMessage *msg)
{
    PlcFrame *Frame  = (PlcFrame*)msg;
    PlcPkt *pkt  = (PlcPkt*)Frame->decapsulate();
    EV << getName() << " meassage received: " << pkt->getData() << endl;
}
