#include "LibInterface.hh"
#include <dlfcn.h>
#include <iostream>

LibInterface::LibInterface()
    : _pLibHandle(nullptr), _pCreateCmd(nullptr), _pGetCmdName(nullptr) {}

LibInterface::~LibInterface() { CloseLibrary(); }

bool LibInterface::LoadLibrary(const std::string& sLibFileName) {
    if (_pLibHandle) CloseLibrary();
    
    _pLibHandle = dlopen(sLibFileName.c_str(), RTLD_NOW);
    if (!_pLibHandle) {
        std::cerr << "dlopen error: " << dlerror() << std::endl;
        return false;
    }
    
    dlerror();
    _pCreateCmd = reinterpret_cast<AbstractInterp4Command* (*)()>(
        dlsym(_pLibHandle, "CreateCmd"));
    if (!_pCreateCmd) {
        std::cerr << "dlsym CreateCmd error: " << dlerror() << std::endl;
        dlclose(_pLibHandle);
        _pLibHandle = nullptr;
        return false;
    }
    
    _pGetCmdName = reinterpret_cast<const char* (*)()>(
        dlsym(_pLibHandle, "GetCmdName"));
    if (!_pGetCmdName) {
        std::cerr << "dlsym GetCmdName error: " << dlerror() << std::endl;
        dlclose(_pLibHandle);
        _pLibHandle = nullptr;
        _pCreateCmd = nullptr;
        return false;
    }
    
    return true;
}

void LibInterface::CloseLibrary() {
    if (_pLibHandle) {
        dlclose(_pLibHandle);
        _pLibHandle = nullptr;
    }
    _pCreateCmd = nullptr;
    _pGetCmdName = nullptr;
}

AbstractInterp4Command* LibInterface::CreateCmd() const {
    return _pCreateCmd ? _pCreateCmd() : nullptr;
}

const char* LibInterface::GetCmdName() const {
    return _pGetCmdName ? _pGetCmdName() : nullptr;
}