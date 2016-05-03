#pragma once
#include "resource.h"

#define TEXT_TABVIEW_MAX_COUNT		8
#define EXTENSION_NAME				".WriterTmp"


namespace Writer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormMain
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		int m_nLen;
		array<String^>^ m_strFileName;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_RMouse;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	public: 
		array<bool>^ m_IsNeedSave;
		int m_RMouseTabIndex;

		
		
		
		FormMain(void)
		{
			m_strFileName = gcnew array< System::String^ >(TEXT_TABVIEW_MAX_COUNT);		//含路徑
	  		m_IsNeedSave = gcnew array< bool >(TEXT_TABVIEW_MAX_COUNT);
			m_strFileName[0] = nullptr;
			m_IsNeedSave[0] = false;
			m_nLen = 0;
			m_RMouseTabIndex = 0;
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControlView;
	private: System::Windows::Forms::TabPage^  New;
	private: System::Windows::Forms::TabPage^  Add;
	protected: 

	protected: 


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  ViewText;

	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			this->tabControlView = (gcnew System::Windows::Forms::TabControl());
			this->New = (gcnew System::Windows::Forms::TabPage());
			this->ViewText = (gcnew System::Windows::Forms::TextBox());
			this->Add = (gcnew System::Windows::Forms::TabPage());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->contextMenuStrip_RMouse = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControlView->SuspendLayout();
			this->New->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->contextMenuStrip_RMouse->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControlView
			// 
			this->tabControlView->AllowDrop = true;
			this->tabControlView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControlView->Controls->Add(this->New);
			this->tabControlView->Controls->Add(this->Add);
			this->tabControlView->Location = System::Drawing::Point(0, 24);
			this->tabControlView->Name = L"tabControlView";
			this->tabControlView->SelectedIndex = 0;
			this->tabControlView->Size = System::Drawing::Size(670, 470);
			this->tabControlView->TabIndex = 0;
			this->tabControlView->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &FormMain::tabControlView_Selected);
			this->tabControlView->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FormMain::tabControlView_MouseClick);
			// 
			// New
			// 
			this->New->Controls->Add(this->ViewText);
			this->New->Location = System::Drawing::Point(4, 22);
			this->New->Name = L"New";
			this->New->Padding = System::Windows::Forms::Padding(3);
			this->New->Size = System::Drawing::Size(662, 444);
			this->New->TabIndex = 0;
			this->New->Text = L"New";
			this->New->UseVisualStyleBackColor = true;
			// 
			// ViewText
			// 
			this->ViewText->AllowDrop = true;
			this->ViewText->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ViewText->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->ViewText->Location = System::Drawing::Point(3, 3);
			this->ViewText->MaxLength = 1000000;
			this->ViewText->Multiline = true;
			this->ViewText->Name = L"ViewText";
			this->ViewText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ViewText->Size = System::Drawing::Size(656, 438);
			this->ViewText->TabIndex = 0;
			this->ViewText->TextChanged += gcnew System::EventHandler(this, &FormMain::NewText_TextChanged);
			this->ViewText->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &FormMain::ViewText_DragDrop);
			this->ViewText->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &FormMain::ViewText_DragEnter);
			this->ViewText->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormMain::NewText_KeyDown);
			// 
			// Add
			// 
			this->Add->Location = System::Drawing::Point(4, 22);
			this->Add->Name = L"Add";
			this->Add->Padding = System::Windows::Forms::Padding(3);
			this->Add->Size = System::Drawing::Size(662, 444);
			this->Add->TabIndex = 1;
			this->Add->Text = L"+";
			this->Add->UseVisualStyleBackColor = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(670, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->loadToolStripMenuItem, 
				this->saveToolStripMenuItem, this->saveAsToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::loadToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->saveAsToolStripMenuItem->Text = L"Save as";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::saveAsToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 497);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(670, 22);
			this->statusStrip1->TabIndex = 2;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(48, 17);
			this->toolStripStatusLabel1->Text = L"字數 : 0";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FormMain::timer1_Tick);
			// 
			// contextMenuStrip_RMouse
			// 
			this->contextMenuStrip_RMouse->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->deleteToolStripMenuItem});
			this->contextMenuStrip_RMouse->Name = L"contextMenuStrip_RMouse";
			this->contextMenuStrip_RMouse->Size = System::Drawing::Size(114, 26);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::deleteToolStripMenuItem_Click);
			// 
			// FormMain
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 519);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->tabControlView);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormMain";
			this->Text = L"Writer";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormMain::FormMain_KeyDown);
			this->tabControlView->ResumeLayout(false);
			this->New->ResumeLayout(false);
			this->New->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->contextMenuStrip_RMouse->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 System::String^ strFileName = m_strFileName[this->tabControlView->SelectedIndex];
			 if (strFileName !=nullptr)
			 {

				 SaveTxtFile(strFileName);

				 //System::Windows::Forms::TextBox^  pTextBox = (System::Windows::Forms::TextBox^)this->tabControlView->SelectedTab->Controls["ViewText"];
				 //System::IO::StreamWriter^ sr = gcnew System::IO::StreamWriter(strFileName,false ,System::Text::Encoding::Default);
				 //if ( (sr) != nullptr )
				 //{
					//sr->Write(pTextBox->Text);
					//sr->Close();

				 //}

				 //System::String^ strTempFileName = gcnew System::String(strFileName);
				 //strTempFileName += EXTENSION_NAME;
				 //bool bIsFindFile = System::IO::File::Exists(strTempFileName);
				 //if (bIsFindFile)
				 //{
					// System::IO::File::Delete(strTempFileName);
				 //}
				 m_IsNeedSave[this->tabControlView->SelectedIndex] = false;
				  
			 }
			 else
			 {
				 saveAsToolStripMenuItem_Click(sender,e);
			 }

			 
		 }
private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 OpenFileDialog openFileDialog; 
			 openFileDialog.InitialDirectory=System::Environment::GetFolderPath(System::Environment::SpecialFolder::Desktop);//預設路徑為桌面
			 openFileDialog.Filter="文字檔|*.txt|所有檔|*.*"; 
			 openFileDialog.RestoreDirectory=true; 
			 openFileDialog.FilterIndex=1; 

			 if (openFileDialog.ShowDialog() == System::Windows::Forms::DialogResult::OK) 
			 {

				 bool bIsFindFile =FindTempFile(openFileDialog.FileName);
				 bool bLoadTempFile = false;
				 if (bIsFindFile)
				 {
					 bLoadTempFile = (System::Windows::Forms::MessageBox::Show("找到未儲存檔案，是否開啟？","Load",System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes);
				 }

				 if (bLoadTempFile)
				 {
					 LoadTxtTempFile(openFileDialog.FileName);
				 }
				 else
				 {
					 LoadTxtFile(openFileDialog.FileName);
				 }
				 

			 }

		 }

private: System::Void LoadTxtFile(System::String^ FilePath) {

			 System::Windows::Forms::TextBox^  pTextBox = (System::Windows::Forms::TextBox^)this->tabControlView->SelectedTab->Controls["ViewText"];

			 System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(FilePath, System::Text::Encoding::Default);
			 pTextBox->Text = sr->ReadToEnd();

			 sr->Close();
			 m_strFileName[this->tabControlView->SelectedIndex] = FilePath;

			 this->tabControlView->SelectedTab->Text = System::IO::Path::GetFileName(FilePath);//取檔案名稱
		 }

private: System::Void SaveTxtFile(System::String^ FilePath) {

			 System::Windows::Forms::TextBox^  pTextBox = (System::Windows::Forms::TextBox^)this->tabControlView->SelectedTab->Controls["ViewText"];
			 System::IO::StreamWriter^ sr = gcnew System::IO::StreamWriter(FilePath,false ,System::Text::Encoding::Default);
			 if ( (sr) != nullptr )
			 {
				 sr->Write(pTextBox->Text);
				 sr->Close();

			 }

			 System::String^ strTempFileName = gcnew System::String(FilePath);
			 strTempFileName += EXTENSION_NAME;
			 bool bIsFindFile = System::IO::File::Exists(strTempFileName);
			 if (bIsFindFile)
			 {
				 System::IO::File::Delete(strTempFileName);
			 }
		 }



private: System::Void LoadTxtTempFile(System::String^ FilePath) {


			 LoadTxtFile(FilePath+EXTENSION_NAME);
			 m_strFileName[this->tabControlView->SelectedIndex] = FilePath;
			 this->tabControlView->SelectedTab->Text = System::IO::Path::GetFileName(FilePath);//取檔案名稱

		}

private: System::Void tabControlView_Selected(System::Object^  sender, System::Windows::Forms::TabControlEventArgs^  e) {

			 
			 if (this->tabControlView->SelectedTab == this->Add)
			 {
				 int nTabCount = this->tabControlView->TabCount;
				 this->tabControlView->Controls->RemoveAt(nTabCount-1);
				 this->tabControlView->Controls->Add(NewPage(System::Drawing::Point(4, 22),System::Drawing::Size(this->tabControlView->Size.Width-8, this->tabControlView->Size.Height-26)));
				 this->tabControlView->SelectTab(nTabCount-1);

				 m_strFileName[nTabCount-1] = nullptr;
				 m_IsNeedSave[nTabCount-1] = false;

				 if (nTabCount < TEXT_TABVIEW_MAX_COUNT)
				 {
					 this->tabControlView->Controls->Add(Add);
				 }

			 }

			 System::Windows::Forms::TextBox^  pTextBox = (System::Windows::Forms::TextBox^)this->tabControlView->SelectedTab->Controls["ViewText"];
			 if (pTextBox)
			 {
				 pTextBox->Tag = false; 
			 }

			 
		 }

		 System::Windows::Forms::TabPage^ NewPage(System::Drawing::Point Page_LeftTop,System::Drawing::Size Page_Size)
		 {
			 System::Windows::Forms::TabPage^ pNewPage = gcnew System::Windows::Forms::TabPage;
			 System::Windows::Forms::TextBox^  pTextBox = gcnew System::Windows::Forms::TextBox();
			 pTextBox->AllowDrop = true;
			 pTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			 pTextBox->Font = (gcnew System::Drawing::Font(L"PMingLiU", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(136)));
			 pTextBox->Location = System::Drawing::Point(0, 3);
			 pTextBox->MaxLength = 1000000;
			 pTextBox->Multiline = true;
			 pTextBox->Name = L"ViewText";
			 pTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			 pTextBox->Size = System::Drawing::Size(Page_Size.Width-3, Page_Size.Height-3);
			 pTextBox->TabIndex = 0;
			 pTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormMain::NewText_KeyDown);
			 pTextBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &FormMain::ViewText_DragDrop);
			 pTextBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &FormMain::ViewText_DragEnter);
			 pTextBox->TextChanged += gcnew System::EventHandler(this, &FormMain::NewText_TextChanged);
			 

			 pNewPage->Controls->Add(pTextBox);
			 pNewPage->Dock = System::Windows::Forms::DockStyle::Fill;
			 pNewPage->Location = Page_LeftTop;
			 pNewPage->Name = L"New";
			 pNewPage->Padding = System::Windows::Forms::Padding(3);
			 pNewPage->Size = Page_Size;
			 pNewPage->TabIndex = 0;
			 pNewPage->Text = L"New";
			 pNewPage->UseVisualStyleBackColor = true;

			 

			 return pNewPage;

		 }



private: System::Void NewText_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {

			 if (e->Control && e->KeyCode == System::Windows::Forms::Keys::A)
			 {

				 System::Windows::Forms::TextBox^  pTextBox = (System::Windows::Forms::TextBox^)sender;
				 
				 pTextBox->SelectAll();
			 }

		 }

private: System::Void NewText_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 System::Windows::Forms::TextBox^  pTextBox = (System::Windows::Forms::TextBox^)sender;
			 //m_nLen = pTextBox->ToString()->Length-36;
			 m_nLen = pTextBox->TextLength;
			 toolStripStatusLabel1->Text = L"字數 : "+m_nLen;
			 
			 //System::String^ strFileName = m_strFileName[this->tabControlView->SelectedIndex];
			 
			 m_IsNeedSave[this->tabControlView->SelectedIndex] = true;

		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {




		 }

private:System::Void SaveAutoTemp(){

			System::String^ strFileName = m_strFileName[this->tabControlView->SelectedIndex];
			
			if (strFileName !=nullptr)
			{

				System::String^ strTempFileName = gcnew System::String(strFileName);
				strTempFileName += EXTENSION_NAME;
				bool bIsFindFile = System::IO::File::Exists(strTempFileName);
				if (bIsFindFile)
				{
					System::IO::File::SetAttributes(strTempFileName,System::IO::FileAttributes::Normal);
				}
				System::Windows::Forms::TextBox^  pTextBox = (System::Windows::Forms::TextBox^)this->tabControlView->SelectedTab->Controls["ViewText"];
				System::IO::StreamWriter^ sr = gcnew System::IO::StreamWriter(strTempFileName,false ,System::Text::Encoding::Default);
				if ( (sr) != nullptr )
				{
					sr->Write(pTextBox->Text);
					sr->Close();

				}
				if (bIsFindFile)
				{
					System::IO::File::SetAttributes(strTempFileName,System::IO::FileAttributes::Hidden);
				}

				
			}


		}
private:bool FindTempFile(System::String^ strFileName){

			if (strFileName !=nullptr)
			{

				System::String^ strTempFileName = gcnew System::String(strFileName);
				strTempFileName += EXTENSION_NAME;
				return System::IO::File::Exists(strTempFileName);
			}
			return false;
		}

private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog;
			 saveFileDialog->Filter = "txt files (*.txt)|*.txt";//|All files (*.*)|*.*";
			 saveFileDialog->FilterIndex = 2;
			 saveFileDialog->RestoreDirectory = true;
			 if ( saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK )
			 {
				 System::Windows::Forms::TextBox^  pTextBox = (System::Windows::Forms::TextBox^)this->tabControlView->SelectedTab->Controls["ViewText"];
				 System::IO::StreamWriter^ sr = gcnew System::IO::StreamWriter(saveFileDialog->FileName,false ,System::Text::Encoding::Default);
				 if ( (sr) != nullptr )
				 {
					 sr->Write(pTextBox->Text);
					 sr->Close();

				 }
				 m_strFileName[this->tabControlView->SelectedIndex] = saveFileDialog->FileName;

				 this->tabControlView->SelectedTab->Text = System::IO::Path::GetFileName(saveFileDialog->FileName);//取檔案名稱
				 
			 }


		 }
private: System::Void tabControlView_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 Point mouseDownLocation = Point(e->X,e->Y);
			 System::String^ eventString = nullptr;
			 switch ( e->Button )
			 {
			 case System::Windows::Forms::MouseButtons::Left:
				 eventString = "L";
				 break;
				 
			 case System::Windows::Forms::MouseButtons::Right:
				 contextMenuStrip_RMouse->Show(this->PointToScreen(mouseDownLocation));

				 
				 for (int i = 0 ; i < this->tabControlView->TabCount ;i++)
				 {
					 if (this->tabControlView->GetTabRect(i).Contains(mouseDownLocation))
					 {
						 m_RMouseTabIndex = i;
					 }

				 }


				 eventString = "R";
				 break;

			 case System::Windows::Forms::MouseButtons::Middle:
				 eventString = "M";


				 System::Windows::Forms::MessageBox::Show(m_strFileName[this->tabControlView->SelectedIndex]);

				 break;

			 case System::Windows::Forms::MouseButtons::None:
			 default:
				 break;
			 }
			 
			 //System::Windows::Forms::MessageBox::Show(eventString);
		 }
private: System::Void deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



			 if (m_IsNeedSave[m_RMouseTabIndex])
			 {
				  this->tabControlView->SelectTab(m_RMouseTabIndex);
				if (System::Windows::Forms::MessageBox::Show("檔案未儲存，是否要先儲存再關閉？","Exit",System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
				{
					SaveTxtFile(m_strFileName[m_RMouseTabIndex]);
					m_IsNeedSave[m_RMouseTabIndex] = false;

				}
			 }


			 int nTabCount = this->tabControlView->TabCount;
			 for (int i = m_RMouseTabIndex ; i < nTabCount ;i++)
			 {
				 if (i+1<TEXT_TABVIEW_MAX_COUNT)
				 {
					 m_strFileName[i] = m_strFileName[i+1];
					 m_IsNeedSave[i] = m_IsNeedSave[i+1];
				 }
			 }
			 m_strFileName[nTabCount-1] = nullptr;
			 m_IsNeedSave[nTabCount-1] = false;
			 this->tabControlView->TabPages->RemoveAt(m_RMouseTabIndex);


			 if (nTabCount <= TEXT_TABVIEW_MAX_COUNT&&!this->tabControlView->Controls["Add"])
			 {
				 this->tabControlView->Controls->Add(Add);
			 }

		 }
private: System::Void ViewText_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			 

			 if (e->Data->GetDataPresent(System::Windows::Forms::DataFormats::FileDrop))
			 {
				 e->Effect = System::Windows::Forms::DragDropEffects::Copy;
			 }

		 }
private: System::Void ViewText_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {


			 array<System::String^>^ strTempFileName = ((array< System::String^ >^)e->Data->GetData(System::Windows::Forms::DataFormats::FileDrop));
			 if (strTempFileName->Length)
			 {
				 int nFileCount = strTempFileName->Length;
				 for (int i = 0 ; i < nFileCount ;i++)
				 {
					 if (System::IO::Path::GetExtension(strTempFileName[i])->ToLower() == ".txt")
					 {

						 bool bIsFindFile =FindTempFile(strTempFileName[i]);
						 bool bLoadTempFile = false;
						 if (bIsFindFile)
						 {
							 bLoadTempFile = (System::Windows::Forms::MessageBox::Show("找到未儲存檔案，是否開啟？","Load",System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes);
						 }

						 if (bLoadTempFile)
						 {
							 LoadTxtTempFile(strTempFileName[i]);
						 }
						 else
						 {
							 LoadTxtFile(strTempFileName[i]);
						 }

						 break;

					 }

				 }
			 }
			 
		 }


private: System::Void FormMain_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			 if (e->Control && e->KeyCode == System::Windows::Forms::Keys::Control)
			 {

				 System::Windows::Forms::
				 System::Windows::Forms::TextBox^  pTextBox = (System::Windows::Forms::TextBox^)sender;

				 pTextBox->SelectAll();
			 }

		 }
};
}

