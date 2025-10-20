#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <string>
#include "AbstractInterp4Command.hh"

class LibInterface {
private:
    void* _pLibHandle;
    AbstractInterp4Command* (*_pCreateCmd)(void);
    const char* (*_pGetCmdName)(void);

public:
    LibInterface();
    ~LibInterface();
    LibInterface(const LibInterface&) = delete;
    LibInterface& operator=(const LibInterface&) = delete;
    
    bool LoadLibrary(const std::string& sLibFileName);
    void CloseLibrary();
    AbstractInterp4Command* CreateCmd() const;
    const char* GetCmdName() const;
};

#endif