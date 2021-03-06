// NintyFont - Nintendo binary font editor
// Copyleft TheDzeraora 2020

// This software is provided under
// the GNU General Public License v3
// See license.txt in the root of the
// source tree for full license conditions
#pragma once

#include <cstdint>
#include <vector>

#include "binarytools/binaryreader.h"
#include "binarytools/binarywriter.h"
#include "binarytools/blocklinker.h"
#include "wid1entry.h"

namespace NintyFont::DOL::Format
{
    class WID1
    {
    private:
        uint32_t entriesOffset; //Used to keep track of where to read the entries from, not in the actual data
    public:
        //Ctors
        WID1(BinaryTools::BinaryReader *br);
        //Dtor
        ~WID1();
        //Methods
        virtual void validateSignature(void);
        virtual void readEntries(BinaryTools::BinaryReader *br);
        virtual void serialize(BinaryTools::BinaryWriter *bw, BinaryTools::BlockLinker *linker);
        //Fields
        uint32_t magic;
        uint32_t length;
        uint16_t startCode; //Code point of first character
        uint16_t endCode; //Code point of last character
        std::vector<WID1Entry *> *entries;
    };
}
