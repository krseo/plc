//
// Generated file, do not edit! Created by nedtool 4.6 from PlcFrame.msg.
//

#ifndef _PLCFRAME_M_H_
#define _PLCFRAME_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>PlcFrame.msg:17</tt> by nedtool.
 * <pre>
 * packet PlcFrame
 * {
 *     int src;
 *     int dst;
 * }
 * </pre>
 */
class PlcFrame : public ::cPacket
{
  protected:
    int src_var;
    int dst_var;

  private:
    void copy(const PlcFrame& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PlcFrame&);

  public:
    PlcFrame(const char *name=NULL, int kind=0);
    PlcFrame(const PlcFrame& other);
    virtual ~PlcFrame();
    PlcFrame& operator=(const PlcFrame& other);
    virtual PlcFrame *dup() const {return new PlcFrame(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSrc() const;
    virtual void setSrc(int src);
    virtual int getDst() const;
    virtual void setDst(int dst);
};

inline void doPacking(cCommBuffer *b, PlcFrame& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PlcFrame& obj) {obj.parsimUnpack(b);}


#endif // ifndef _PLCFRAME_M_H_
