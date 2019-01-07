#include "mainwindow.h"
#include "testcaser/integrator"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QIntValidator>
#include <QMessageBox>
#include <future>
#include <thread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(width(), height());
  ui->label_2->setEnabled(false);
  ui->lineEdit_3->setEnabled(false);

  ui->label_3->setFont(QFont("consolas", 8, -1, true));
  ui->label_4->setFont(QFont("consolas", 8, -1, true));

  set_tool_tips_to_widgets();
  set_Validators();

  make_progress_invisible();
  make_result_invisible();
  make_step_one_visible();

  //  // For debug purpose
  //  make_result_visible();
  //  make_progress_invisible();
  //  make_step_one_invisible();
}

void MainWindow::set_tool_tips_to_widgets() {
  ui->executable_label->setToolTip(
      "The Executable or the script that you want the virtual judge to run");
  ui->label_3->setToolTip(
      "The Chosen Executable or Script name will appear here");
  ui->choose_button_2->setToolTip("Opens a File Choosing Dialog");
  ui->executable_label_2->setToolTip(
      "The Input file from where the executable will read to stdin");
  ui->label_4->setToolTip("The Chosen Input file name will appear here");
  ui->choose_button_3->setToolTip("Opens a File Choosing Dialog");
  ui->time_label->setToolTip(
      "The Time limit to set to the Program in Seconds.");
  ui->lineEdit_2->setToolTip("Enter the time is seconds.");
  ui->memory_label->setToolTip("Sets the Physical memory limit to the Program");
  ui->lineEdit->setToolTip("Enter the Memory Value in MB");
  ui->label_2->setToolTip(
      "If above time limit is exceeded. The Program will continue to "
      "execute until this given time is reached, Once reached Judge will send "
      "a SIGKILL to the executable");
  ui->lineEdit_3->setToolTip("Enter the wait time in seconds");
  ui->checkBox->setToolTip(
      "By default Judge will SIGKILL the executable as soon as time limit "
      "exceeds. It disables this behaviour.");
}

void MainWindow::set_Validators() {
  ui->lineEdit_2->setValidator(new QIntValidator(1, 1000, this));
  ui->lineEdit->setValidator(new QIntValidator(1, 1024 * 2, this));
  ui->lineEdit_3->setValidator(new QIntValidator(1, 1000 * 5, this));
}

void MainWindow::make_step_one_invisible() {
  ui->executable_label->hide();
  ui->executable_label_2->hide();
  ui->checkBox->hide();
  ui->choose_button_2->hide();
  ui->choose_button_3->hide();
  ui->exit_button->hide();
  ui->label->hide();
  ui->label_2->hide();
  ui->label_3->hide();
  ui->label_4->hide();
  ui->line->hide();
  ui->lineEdit->hide();
  ui->lineEdit_2->hide();
  ui->lineEdit_3->hide();
  ui->memory_label->hide();
  ui->pushButton_2->hide();
  ui->time_label->hide();
}

void MainWindow::make_step_one_visible() {
  ui->executable_label->show();
  ui->executable_label_2->show();
  ui->checkBox->show();
  ui->choose_button_2->show();
  ui->choose_button_3->show();
  ui->exit_button->show();
  ui->label->show();
  ui->label_2->show();
  ui->label_3->show();
  ui->label_4->show();
  ui->line->show();
  ui->lineEdit->show();
  ui->lineEdit_2->show();
  ui->lineEdit_3->show();
  ui->memory_label->show();
  ui->pushButton_2->show();
  ui->time_label->show();
}

void MainWindow::make_progress_invisible() {
  ui->label_5->hide();
  // ui->progressBar->hide();
}

void MainWindow::make_progress_visible() {
  ui->label_5->show();
  // ui->progressBar->show();
}

void MainWindow::make_result_invisible() {
  ui->label_6->hide();
  ui->label_7->hide();
  ui->label_8->hide();
  ui->label_9->hide();
  ui->label_10->hide();
  ui->label_11->hide();
  ui->label_12->hide();
  ui->label_13->hide();
  ui->label_14->hide();
  ui->label_15->hide();
  ui->label_16->hide();
  ui->label_17->hide();
  ui->label_18->hide();
  ui->label_19->hide();
  ui->label_20->hide();
  ui->line_2->hide();
  ui->line_3->hide();
  ui->line_4->hide();
  ui->line_5->hide();
  ui->pushButton_3->hide();
  ui->pushButton->hide();
}

void MainWindow::make_result_visible() {
  ui->label_6->show();
  ui->label_7->show();
  ui->label_8->show();
  ui->label_9->show();
  ui->label_10->show();
  ui->label_11->show();
  ui->label_12->show();
  ui->label_13->show();
  ui->label_14->show();
  ui->label_15->show();
  ui->label_16->show();
  ui->label_17->show();
  ui->label_18->show();
  ui->label_19->show();
  ui->label_20->show();
  ui->line_2->show();
  ui->line_3->show();
  ui->line_4->show();
  ui->line_5->show();
  ui->pushButton_3->show();
  ui->pushButton->show();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_exit_button_clicked() {
  QMessageBox confirm_exit(this);
  confirm_exit.setText("Are you sure you want to Exit VirtualJudge?");
  confirm_exit.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
  confirm_exit.setDefaultButton(QMessageBox::Yes);
  int ret = confirm_exit.exec();
  if (ret == QMessageBox::Yes) {
    exit(0);
  }
}

void MainWindow::on_pushButton_2_clicked() {
  if (!this->has_file_been_chosen) {
    QMessageBox box(this);
    box.setText("Opps !!! Did you not forgot to choose the executable");
    box.exec();
    return;
  }
  if (!this->has_input_been_choosen) {
    QMessageBox box(this);
    box.setText("Opps !!! Did you not forgot to choose the input file");
    box.exec();
    return;
  }
  if (ui->lineEdit->text().isEmpty()) {
    QMessageBox box(this);
    box.setText("Opps !!! Did you not forgot to set memory limit");
    box.exec();
    return;
  }
  if (ui->lineEdit_2->text().isEmpty()) {
    QMessageBox box(this);
    box.setText("Opps !!! Did you not forgot to set time limit");
    box.exec();
    return;
  }
  if (ui->checkBox->isChecked()) {
    QMessageBox box(this);
    if (ui->lineEdit_2->text().isEmpty()) {
      box.setText("Opps !!! You have missed to provide the auto exit time.");
      box.exec();
      return;
    }
  }
  make_step_one_invisible();
  make_progress_visible();
  using testcaser::integrator::VirtualJudge;
  output_file = input_file.substr(0, input_file.find_last_of("/\\"));
  output_file += "/output.txt";
  try {
    auto session =
        VirtualJudge()
            .set_auto_exit(!ui->checkBox->isChecked())
            .set_binary(executable_path)
            .set_input_file(input_file)
            .set_auto_exit_time_limit(
                static_cast<size_t>(ui->lineEdit_3->text().toInt()))
            .set_time_limit(static_cast<size_t>(ui->lineEdit_2->text().toInt()))
            .set_output_file(output_file)
            .set_memory_limit(
                static_cast<size_t>(ui->lineEdit->text().toInt()) * 1024);

    make_progress_visible();
    this->repaint();
    auto handle = AsyncExecute(session);

    // This block can be removed
    while (!(handle.wait_for(std::chrono::seconds(0)) ==
             std::future_status::ready)) {
      make_progress_visible();
      make_result_invisible();
      make_step_one_invisible();
    }

    auto result = handle.get();
    make_progress_invisible();
    make_step_one_invisible();
    setUpResults(result);
    make_result_visible();

    result.print_result();
  } catch (std::exception &e) {
    make_step_one_visible();
    make_result_invisible();
    make_progress_invisible();
    QMessageBox box(this);
    box.setText("Internal Error Occured while execution");
    box.setInformativeText(e.what());
    box.exec();
  }
}

void MainWindow::on_checkBox_stateChanged(int arg1) {
  ui->label_2->setEnabled(arg1 != 0);
  ui->lineEdit_3->setEnabled(arg1 != 0);
}

void MainWindow::on_choose_button_2_clicked() {
  QFileDialog dialog(this);
  dialog.setFileMode(QFileDialog::AnyFile);
  QStringList files;
  if (dialog.exec()) {
    files = dialog.selectedFiles();
    this->has_file_been_chosen = true;
    std::string name = files[0].toStdString();
    this->executable_path = name;
    std::size_t found = name.find_last_of("/\\");
    ui->label_3->setText(QString::fromStdString(name.substr(found + 1)));
  }
}

void MainWindow::on_choose_button_3_clicked() {
  QFileDialog dialog(this);
  dialog.setFileMode(QFileDialog::AnyFile);
  QStringList files;
  if (dialog.exec()) {
    this->has_input_been_choosen = true;
    files = dialog.selectedFiles();
    std::string name = files[0].toStdString();
    this->input_file = name;
    std::size_t found = name.find_last_of("/\\");
    ui->label_4->setText(QString::fromStdString(name.substr(found + 1)));
  }
}

void MainWindow::setUpResults(testcaser::integrator::Result res) {
  auto time = static_cast<size_t>(ui->lineEdit_2->text().toInt());
  auto memory = static_cast<size_t>(ui->lineEdit->text().toInt()) * 1024;
  auto umem = res.get_physical_memory_used();
  auto umem2 = res.get_virtual_memory_used();
  auto etime = res.get_execution_time();
  auto ecode = res.get_exit_code();
  auto remark = res.parse_exit_status(res.get_exit_status());
  ui->label_14->setText(
      QString::fromStdString(std::to_string(memory) + " KB (" +
                             std::to_string(memory / 1024.0) + " MB)"));
  ui->label_15->setText(QString::fromStdString(
      std::to_string(umem) + " KB (" + std::to_string(umem / 1024.0) + " MB)"));
  ui->label_16->setText(
      QString::fromStdString(std::to_string(umem2) + " KB (" +
                             std::to_string((umem2 / 1024.0)) + " MB)"));
  ui->label_17->setText(
      QString::fromStdString(std::to_string(time) + " second(s)"));
  ui->label_18->setText(
      QString::fromStdString(std::to_string(etime) + " second(s)"));
  ui->label_19->setText(QString::fromStdString(std::to_string(ecode)));
  ui->label_20->setText(QString::fromStdString(remark));
}

void MainWindow::on_pushButton_3_clicked() { on_exit_button_clicked(); }

void MainWindow::on_pushButton_clicked() {
  make_step_one_visible();
  make_progress_invisible();
  make_result_invisible();
  reset();
}

void MainWindow::reset() {
  has_file_been_chosen = false;
  has_input_been_choosen = false;
  ui->label_3->setText("No File Chosen");
  ui->label_4->setText("No File Chosen");
  ui->lineEdit->clear();
  ui->lineEdit_2->clear();
  ui->lineEdit_3->clear();
  ui->checkBox->setCheckState(Qt::CheckState::Unchecked);
}

std::future<testcaser::integrator::Result>
MainWindow::AsyncExecute(testcaser::integrator::VirtualJudge &session) {
  return std::async(std::launch::async,
                    [&session]() { return session.execute(); });
}
