#include "IButton.h"
#include "IBtnController.h"
#include "IShapeBtnController.h"

#include "IEditor/IEditorView.h"
#include "IEditor/IEditorModel.h"
#include "IEditor/IEditorController.h"


/**
 * @brief Главное окно редактора
 */
class MainWindow
{
    std::shared_ptr<IEditorModel> model;
    std::shared_ptr<IEditorController> controller;
    std::shared_ptr<IEditorView> view; ///< виджет для рисования

    std::unique_ptr<IButton> createDoc_btn;
    std::unique_ptr<IButton> importDoc_btn;
    std::unique_ptr<IButton> exportDoc_btn;

    std::unique_ptr<IButton> drawPoint_btn;
    std::unique_ptr<IButton> drawLine_btn;
    std::unique_ptr<IButton> drawTriangle_btn;

public:
    MainWindow()
    {
        model = std::make_shared<GraphicModel>();
        controller = std::make_shared<GraphicController>(model);
        view = std::make_shared<GraphicView>(model, controller);
        model->setView(view);

        createDoc_btn = std::make_unique<PushButton>(std::make_unique<DocCreateBtnCtrl>());
        importDoc_btn = std::make_unique<PushButton>(std::make_unique<DocImportBtnCtrl>());
        exportDoc_btn = std::make_unique<PushButton>(std::make_unique<DocExportBtnCtrl>());

        drawPoint_btn = std::make_unique<ToggleButton>(std::make_unique<PointBtnCtrl>(controller));
        drawLine_btn = std::make_unique<ToggleButton>(std::make_unique<LineBtnCtrl>(controller));
        drawTriangle_btn = std::make_unique<ToggleButton>(std::make_unique<TriangleBtnCtrl>(controller));
    }

    void test()
    {
        createDoc_btn->click();
        importDoc_btn->click();
        exportDoc_btn->click();
        {
            drawPoint_btn->click();
            view->leftClick(5, 10);
        }
        {
            drawLine_btn->click();
            view->leftClick(7, 5);
            view->leftClick(5, 7);
        }
        {
            drawTriangle_btn->click();
            view->leftClick(10, 15);
            view->leftClick(7, 11);
            view->leftClick(14, 9);
        }
    }
};