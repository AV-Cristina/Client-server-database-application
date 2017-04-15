object Form1: TForm1
  Left = 298
  Top = 81
  Width = 540
  Height = 345
  Caption = 'My Software'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 525
    Height = 297
    TabOrder = 0
  end
  object ComboBox1: TComboBox
    Left = 20
    Top = 220
    Width = 101
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 1
    Visible = False
  end
  object IBDatabase1: TIBDatabase
    DefaultTransaction = IBTransaction1
    IdleTimer = 0
    SQLDialect = 3
    TraceFlags = []
    Left = 156
    Top = 252
  end
  object IBTransaction1: TIBTransaction
    Active = False
    DefaultDatabase = IBDatabase1
    AutoStopAction = saNone
    Left = 192
    Top = 256
  end
  object DataSource2: TDataSource
    DataSet = IBQuery2
    Left = 332
    Top = 252
  end
  object DataSource3: TDataSource
    DataSet = IBQuery3
    Left = 396
    Top = 252
  end
  object IBQuery1: TIBQuery
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 292
    Top = 248
  end
  object IBQuery2: TIBQuery
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 364
    Top = 252
  end
  object IBQuery3: TIBQuery
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 424
    Top = 264
  end
  object DataSource1: TDataSource
    DataSet = IBQuery1
    Left = 260
    Top = 252
  end
  object IBQuery4: TIBQuery
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 228
    Top = 248
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 0
    ServerType = stNonBlocking
    ThreadCacheSize = 60
    OnClientConnect = ServerSocket1ClientConnect
    OnClientRead = ServerSocket1ClientRead
    Left = 120
    Top = 248
  end
  object DataSource4: TDataSource
    DataSet = IBQuery5
    Left = 484
    Top = 260
  end
  object IBQuery5: TIBQuery
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 456
    Top = 264
  end
end
