#include "bwidget.h"

BWidget::BWidget(QWidget* parent, Biblioteca* b) : QWidget(parent), biblioteca(b) {} // BWidget

Biblioteca* BWidget::b() {
    return biblioteca;
} // b
