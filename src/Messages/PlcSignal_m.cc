//
// Generated file, do not edit! Created by nedtool 4.6 from PlcSignal.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PlcSignal_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(PlcSignal);

PlcSignal::PlcSignal(const char *name, int kind) : ::cPacket(name,kind)
{
    this->duration_var = 0;
    this->snr_var = 0;
    this->lossrate_var = 0;
    this->bitrate_var = 0;
}

PlcSignal::PlcSignal(const PlcSignal& other) : ::cPacket(other)
{
    copy(other);
}

PlcSignal::~PlcSignal()
{
}

PlcSignal& PlcSignal::operator=(const PlcSignal& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void PlcSignal::copy(const PlcSignal& other)
{
    this->duration_var = other.duration_var;
    this->snr_var = other.snr_var;
    this->lossrate_var = other.lossrate_var;
    this->bitrate_var = other.bitrate_var;
}

void PlcSignal::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->duration_var);
    doPacking(b,this->snr_var);
    doPacking(b,this->lossrate_var);
    doPacking(b,this->bitrate_var);
}

void PlcSignal::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->duration_var);
    doUnpacking(b,this->snr_var);
    doUnpacking(b,this->lossrate_var);
    doUnpacking(b,this->bitrate_var);
}

simtime_t PlcSignal::getDuration() const
{
    return duration_var;
}

void PlcSignal::setDuration(simtime_t duration)
{
    this->duration_var = duration;
}

double PlcSignal::getSnr() const
{
    return snr_var;
}

void PlcSignal::setSnr(double snr)
{
    this->snr_var = snr;
}

double PlcSignal::getLossrate() const
{
    return lossrate_var;
}

void PlcSignal::setLossrate(double lossrate)
{
    this->lossrate_var = lossrate;
}

double PlcSignal::getBitrate() const
{
    return bitrate_var;
}

void PlcSignal::setBitrate(double bitrate)
{
    this->bitrate_var = bitrate;
}

class PlcSignalDescriptor : public cClassDescriptor
{
  public:
    PlcSignalDescriptor();
    virtual ~PlcSignalDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlcSignalDescriptor);

PlcSignalDescriptor::PlcSignalDescriptor() : cClassDescriptor("PlcSignal", "cPacket")
{
}

PlcSignalDescriptor::~PlcSignalDescriptor()
{
}

bool PlcSignalDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlcSignal *>(obj)!=NULL;
}

const char *PlcSignalDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlcSignalDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int PlcSignalDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *PlcSignalDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "duration",
        "snr",
        "lossrate",
        "bitrate",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int PlcSignalDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "snr")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "lossrate")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitrate")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PlcSignalDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *PlcSignalDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PlcSignalDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlcSignal *pp = (PlcSignal *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PlcSignalDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PlcSignal *pp = (PlcSignal *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getDuration());
        case 1: return double2string(pp->getSnr());
        case 2: return double2string(pp->getLossrate());
        case 3: return double2string(pp->getBitrate());
        default: return "";
    }
}

bool PlcSignalDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlcSignal *pp = (PlcSignal *)object; (void)pp;
    switch (field) {
        case 0: pp->setDuration(string2double(value)); return true;
        case 1: pp->setSnr(string2double(value)); return true;
        case 2: pp->setLossrate(string2double(value)); return true;
        case 3: pp->setBitrate(string2double(value)); return true;
        default: return false;
    }
}

const char *PlcSignalDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *PlcSignalDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlcSignal *pp = (PlcSignal *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


