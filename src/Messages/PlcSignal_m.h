//
// Generated file, do not edit! Created by nedtool 4.6 from PlcSignal.msg.
//

#ifndef _PLCSIGNAL_M_H_
#define _PLCSIGNAL_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>PlcSignal.msg:17</tt> by nedtool.
 * <pre>
 * packet PlcSignal
 * {
 *     simtime_t duration;
 *     double snr;
 *     double lossrate;
 *     double bitrate;
 * }
 * </pre>
 */
class PlcSignal : public ::cPacket
{
  protected:
    simtime_t duration_var;
    double snr_var;
    double lossrate_var;
    double bitrate_var;

  private:
    void copy(const PlcSignal& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PlcSignal&);

  public:
    PlcSignal(const char *name=NULL, int kind=0);
    PlcSignal(const PlcSignal& other);
    virtual ~PlcSignal();
    PlcSignal& operator=(const PlcSignal& other);
    virtual PlcSignal *dup() const {return new PlcSignal(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual simtime_t getDuration() const;
    virtual void setDuration(simtime_t duration);
    virtual double getSnr() const;
    virtual void setSnr(double snr);
    virtual double getLossrate() const;
    virtual void setLossrate(double lossrate);
    virtual double getBitrate() const;
    virtual void setBitrate(double bitrate);
};

inline void doPacking(cCommBuffer *b, PlcSignal& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PlcSignal& obj) {obj.parsimUnpack(b);}


#endif // ifndef _PLCSIGNAL_M_H_
