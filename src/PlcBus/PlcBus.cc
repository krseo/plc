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

#include "PlcBus.h"

Define_Module(PlcBus);


PlcBus::PlcBus()
{
    tap = NULL;
}

PlcBus::~PlcBus()
{
    delete [] tap;
}


void PlcBus::initialize()
{
    propagationSpeed=2e8;
    length = par("length"); // import parameters

    // read positions and check if positions are defined in order (we're lazy to sort...)
    std::vector<double> pos = cStringTokenizer(par("positions").stringValue()).asDoubleVector();
    int numPos = pos.size();
    numTaps = gateSize("gt"); //
    tap = new BusTap[numTaps];

    if(numTaps != numPos){
        EV << "Error(Ned): taps and positions differ!!\n";
        //exit(0);
        // 추후 에러처리 주가
    }

    int i;

    for (i = 0; i < numTaps; i++)
        {
            tap[i].id = i;
            tap[i].position = pos[i];
            EV << "position " << i << " is " << tap[i].position ;
    }

   for (int i = 0; i < numTaps-1; i++)
    {
        if (tap[i].position > tap[i+1].position)
            error("Tap positions must be ordered in ascending fashion, modify 'positions' parameter and rerun\n");
    }
}
void PlcBus::finish()
{
    // TODO - Generated method body
}

void PlcBus::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
    {
        EV << "BUS: Frame " << msg << " Scheduled arrived on tap " << endl;
        int idx;
        //idx = msg->getKind()
        send(msg, "gt$o", msg->getKind());
    }
    else   {
        // Handle frame sent down from the network entity
        int tapPoint = msg->getArrivalGate()->getIndex();
        EV << "BUS: Frame " << msg << " arrived on tap " << tapPoint << endl;
        int i;
        double delay;
        for (i=0;i<numTaps;i++){
            if(i != tapPoint){
                delay = abs(tap[tapPoint].position-tap[i].position)/propagationSpeed;
                EV << "delay " << tapPoint <<" to" << i << " is " << delay << endl;
                cMessage *msg2 = msg->dup();
                msg2->setKind(i);
                msg2->addPar("delay");
                msg2->par("delay").setLongValue(delay);
                scheduleAt(simTime()+delay, msg2);
            }
        }
    }

}
