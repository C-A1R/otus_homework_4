#ifndef IBTNCONTROLLER
#define IBTNCONTROLLER

#include "IEditor/IEditorController.h"

#include <iostream>


/**
 * @brief Интерфейс контроллеров для кнопок
 */
class IBtnController
{
public:
    IBtnController() = default;
    virtual ~IBtnController() = default;
    virtual void exec() = 0;
    virtual void cancel() = 0;
};

/**
 * @brief Создать документ
 */
class DocCreateBtnCtrl : public IBtnController
{
public:
    DocCreateBtnCtrl() = default;
    void exec() override
    {
        std::cout << "#_create_new_document" << std::endl;
    }
    void cancel() override
    {
    }
};

/**
 * @brief Импорт документа
 */
class DocImportBtnCtrl : public IBtnController
{
public:
    DocImportBtnCtrl() = default;
    void exec() override
    {
        std::cout << "#_import_document_from_file" << std::endl;
    }
    void cancel() override
    {
    }
};

/**
 * @brief Экспорт документа
 */
class DocExportBtnCtrl : public IBtnController
{
public:
    DocExportBtnCtrl() = default;
    void exec() override
    {
        std::cout << "#_export_document_to_file" << std::endl;
    }
    void cancel() override
    {
    }
};

#endif //IBTNCONTROLLER