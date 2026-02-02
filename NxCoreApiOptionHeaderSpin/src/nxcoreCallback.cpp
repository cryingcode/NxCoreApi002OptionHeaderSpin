// file:  nxcoreCallback.cpp

#include "nxcoreCallback.hpp"
#include "processNxCoreStatusMessage.hpp"
#include "processNxCoreSymbolSpinMessage.hpp"

extern NxCoreClass NxCore; // defined in main.cpp

int OnNxCoreCallback(const NxCoreSystem *pNxCoreSys, const NxCoreMessage *pNxCoreMsg)
{
    switch (pNxCoreMsg->MessageType)
    {
    case NxMSG_STATUS:
        return processNxCoreStatusMessage(pNxCoreSys);
    case NxMSG_EXGQUOTE:
    case NxMSG_MMQUOTE:
    case NxMSG_TRADE:
    case NxMSG_CATEGORY:
    case NxMSG_SYMBOLCHANGE:
        break;
    case NxMSG_SYMBOLSPIN:
        return processNxCoreSymbolSpinMessage(pNxCoreSys, pNxCoreMsg);
    }

    return NxCALLBACKRETURN_CONTINUE;
}