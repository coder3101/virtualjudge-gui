#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "testcaser/integrator"
#include <QMainWindow>
#include <future>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  bool has_file_been_chosen = false;
  bool has_input_been_choosen = false;

  std::string input_file, output_file, executable_path;

  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow();

private slots:
  void on_exit_button_clicked();

  void on_pushButton_2_clicked();

  void on_checkBox_stateChanged(int arg1);

  void on_choose_button_2_clicked();

  void on_choose_button_3_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
  void set_tool_tips_to_widgets();
  void set_Validators();
  void make_step_one_invisible();
  void make_step_one_visible();
  void make_result_visible();
  void make_result_invisible();
  void make_progress_visible();
  void make_progress_invisible();
  void setUpResults(testcaser::integrator::Result);
  std::future<testcaser::integrator::Result>
  AsyncExecute(testcaser::integrator::VirtualJudge &session);

  void reset();
};

#endif // MAINWINDOW_H
