// NintyFont - Nintendo binary font editor
// Copyleft TheDzeraora 2020

// This software is provided under
// the GNU General Public License v3
// See license.txt in the root of the
// source tree for full license conditions

// Header file for a UTF-16 code point picker GUI
// control class for the dynamic property system
#pragma once

#include <cstdint>
#include <QtWidgets>

#include "globalstuffs.h"
#include "qhexspinbox.h"
#include "control.h"

namespace NintyFont::GUI::Controls
{
    class CodePointPicker : public QFormLayout, public Control
    {
    private:
        std::vector<PropertyList::PropertyBase *> **propList; //Pointer to a pointer to property list of the selected glyph. Should be set to nullptr if no glyph is selected (or more than one is selected)
        PropertyList::PropertyListEntryDescriptor *descriptor;
        GlobalStuffs *globals;
        //GUI
        QLabel *glyphLabel;
        QLabel *glyphNameLabel;
        QHexSpinBox *codePointEdit;
        //Private methods
        void updateProperty(void);
        void updateGlyphNameLabels(uint16_t code);
    public:
        //Ctor
        CodePointPicker(std::vector<PropertyList::PropertyBase *> **propList, PropertyList::PropertyListEntryDescriptor *descriptor, GlobalStuffs *globals, QWidget *parent = nullptr);
        //Dtor
        ~CodePointPicker();
        //Public methods
        void update(void) override;
        void lockControl(void) override;
        void unlockControl(void) override;
    };
}
