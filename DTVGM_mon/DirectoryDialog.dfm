object DirectoryDlg: TDirectoryDlg
  Left = 348
  Top = 364
  BorderStyle = bsDialog
  Caption = 'DirectoryDialog'
  ClientHeight = 239
  ClientWidth = 473
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 8
    Width = 377
    Height = 225
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 200
    Top = 192
    Width = 45
    Height = 13
    Caption = 'Drivers:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_dir: TLabel
    Left = 200
    Top = 32
    Width = 55
    Height = 13
    BiDiMode = bdLeftToRight
    Caption = 'D:\DTVGM'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
    Transparent = True
    WordWrap = True
  end
  object Label2: TLabel
    Left = 5
    Top = 16
    Width = 61
    Height = 13
    Caption = 'File Name:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 200
    Top = 16
    Width = 66
    Height = 13
    Caption = 'Directories:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 5
    Top = 192
    Width = 102
    Height = 13
    Caption = 'List Files of Type:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object OKBtn: TButton
    Left = 388
    Top = 12
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 388
    Top = 44
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 200
    Top = 56
    Width = 172
    Height = 129
    FileList = FileListBox1
    ImeName = #20013#25991' ('#31616#20307') - '#24494#36719#25340#38899
    ItemHeight = 16
    TabOrder = 2
    OnChange = DirectoryListBox1Change
  end
  object DriveComboBox1: TDriveComboBox
    Left = 200
    Top = 208
    Width = 172
    Height = 19
    DirList = DirectoryListBox1
    ImeName = #32043#20809#25340#38899#36755#20837#27861
    TabOrder = 3
  end
  object FileListBox1: TFileListBox
    Left = 5
    Top = 56
    Width = 180
    Height = 128
    FileEdit = EditFile
    ImeName = #32043#20809#25340#38899#36755#20837#27861
    ItemHeight = 13
    TabOrder = 4
  end
  object EditFile: TEdit
    Left = 5
    Top = 35
    Width = 180
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ImeName = #32043#20809#25340#38899#36755#20837#27861
    ParentFont = False
    TabOrder = 5
    Text = '*.*'
  end
  object FilterComboBox1: TFilterComboBox
    Left = 5
    Top = 208
    Width = 180
    Height = 21
    FileList = FileListBox1
    Filter = 
      'All files (*.*)|*.*|Text files(*.txt;*.asc;*.dat)|*.txt;*.asc;*.' +
      'dat|Excel files(*.xls)|*.xls|Word files(*.doc)|*.doc|Picture fil' +
      'es(*.jpg;*.jpeg;*.bmp;*.tif)|*.jpg;*.jpeg;*.bmp;*.tif|C++ Head f' +
      'iles(*.h)|*.h|Output files(*.out)|*.out'
    ImeName = #32043#20809#25340#38899#36755#20837#27861
    TabOrder = 6
  end
end
