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

package plc.src.Plctst;
import plc.src.*.*;

module PlcNode
{
    gates:
        inout gt;
    submodules:
        App: PlcApp;
        Nic: PlcNic;
    connections:
        App.InFromMac <-- Nic.OutToApp;
        App.OutToMac --> Nic.InFromApp;
        gt <--> Nic.gt;
}

network TstNet1
{
    parameters:
        Node[1..2].App.Apptype="Meter";
        Node[0].App.Apptype="Head";
    submodules:
        Node[3]: PlcNode;
        Bus: PlcBus {
            parameters:
                positions = "0 100 200";
            gates:
                gt[3];
        }
    connections:
        for i=0..2{
        	Node[i].gt <--> Bus.gt[i];
        }
}
