object Form1: TForm1
  Left = 542
  Top = 131
  Width = 652
  Height = 452
  Caption = 'My Software'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 644
    Height = 398
    ActivePage = TabSheet2
    Align = alClient
    TabIndex = 1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1085#1099#1077' '#1087#1088#1086#1077#1082#1090#1099
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 636
        Height = 370
        Align = alClient
        ColCount = 7
        FixedColor = clMenuBar
        FixedCols = 0
        RowCount = 2
        TabOrder = 0
        ColWidths = (
          213
          110
          125
          134
          82
          138
          201)
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1052#1086#1076#1091#1083#1080' '#1080' '#1073#1080#1073#1083#1080#1086#1090#1077#1082#1080
      ImageIndex = 1
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 636
        Height = 370
        Align = alClient
        ColCount = 4
        FixedCols = 0
        RowCount = 2
        TabOrder = 0
        ColWidths = (
          241
          127
          197
          128)
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1047#1072#1082#1072#1079#1095#1080#1082#1080
      ImageIndex = 2
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 636
        Height = 370
        Align = alClient
        FixedColor = clMenuBar
        FixedCols = 0
        RowCount = 2
        TabOrder = 0
        ColWidths = (
          116
          119
          131
          131
          136)
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 348
    Top = 65532
    object N6: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object N12: TMenuItem
        Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1079#1072#1087#1080#1089#1100
        OnClick = N12Click
      end
      object N1: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
        OnClick = N1Click
      end
      object N11: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
        OnClick = N11Click
      end
    end
    object N7: TMenuItem
      Caption = #1044#1072#1085#1085#1099#1077
      object N9: TMenuItem
        Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100' '#1092#1080#1083#1100#1090#1088
        OnClick = N9Click
      end
      object N13: TMenuItem
        Caption = #1054#1090#1084#1077#1085#1080#1090#1100' '#1092#1080#1083#1100#1090#1088
        OnClick = N13Click
      end
      object N8: TMenuItem
        Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
        OnClick = N8Click
      end
      object N10: TMenuItem
        Caption = #1053#1072#1081#1090#1080
        OnClick = N10Click
      end
    end
    object N2: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N3: TMenuItem
        Caption = #1056#1091#1082#1086#1074#1086#1076#1089#1090#1074#1086' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1054#1090#1095#1077#1090
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = N5Click
      end
    end
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnect = ClientSocket1Connect
    OnRead = ClientSocket1Read
    Left = 384
    Top = 65532
  end
end
