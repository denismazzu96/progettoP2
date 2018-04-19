// fe/widget/bookform.h

#ifndef BOOKFORM_H
#define BOOKFORM_H

// back-end
#include "../../be/contenitore/libromod.h"

// front-end
#include "form.h"

// Qt
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QPointer>

class BookForm : public Form {
    Q_OBJECT
private:
    QPointer<QLineEdit> au_txt, ti_txt, ce_txt, ge_txt, an_txt, gr_txt, nc_txt;
public:
    BookForm(QWidget* =nullptr, const QString& ="Aggiungi");

    QLineEdit* getLineEdit(const QString&) const;
private slots:
    void _clicked();
}; // BookForm

#endif // BOOKFORM_H
