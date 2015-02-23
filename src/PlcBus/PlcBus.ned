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

package plc.src.PlcBus;

//
// TODO auto-generated module
//
simple PlcBus
{
    parameters:
        @node();
        @labels(node,PLC-node);
        @display("b=200,5,,,,1");
        double length @unit("m") = default(1000m);
        string positions;  // positions of taps on the cable in meters, as a sequence
                           // of numbers separated by spaces. If there are too
                           // few values, the distance between the last two positions
                           // is repeated, or 5 meters is used.
        //double propagationSpeed @unit("mps") = default(200000000mps); // signal propagation speed on the bus
    gates:
        inout gt[] @labels(PLCFrame-conn);  // to stations; each one represents a tap
}
