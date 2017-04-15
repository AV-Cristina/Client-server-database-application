object Form4: TForm4
  Left = 331
  Top = 7
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1055#1086#1080#1089#1082
  ClientHeight = 443
  ClientWidth = 627
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 520
    Top = 408
    Width = 97
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 0
    OnClick = Button1Click
  end
  object GroupBox1: TGroupBox
    Left = 4
    Top = 0
    Width = 621
    Height = 77
    Color = clBtnFace
    ParentColor = False
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 20
      Width = 57
      Height = 13
      Caption = #1050#1088#1080#1090#1077#1088#1080#1081' 1'
    end
    object Label2: TLabel
      Left = 296
      Top = 20
      Width = 107
      Height = 13
      Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1082#1088#1080#1090#1077#1088#1080#1103' 1'
    end
    object Label3: TLabel
      Left = 8
      Top = 52
      Width = 57
      Height = 13
      Caption = #1050#1088#1080#1090#1077#1088#1080#1081' 2'
    end
    object Label4: TLabel
      Left = 296
      Top = 52
      Width = 107
      Height = 13
      Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1082#1088#1080#1090#1077#1088#1080#1103' 2'
    end
    object ComboBox1: TComboBox
      Left = 68
      Top = 12
      Width = 213
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 408
      Top = 12
      Width = 201
      Height = 21
      TabOrder = 1
    end
    object ComboBox2: TComboBox
      Left = 68
      Top = 44
      Width = 213
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 2
    end
    object Edit2: TEdit
      Left = 408
      Top = 44
      Width = 201
      Height = 21
      TabOrder = 3
    end
  end
  object GroupBox3: TGroupBox
    Left = 4
    Top = 164
    Width = 621
    Height = 229
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1087#1086#1080#1089#1082#1072
    TabOrder = 2
    object StringGrid1: TStringGrid
      Left = 4
      Top = 16
      Width = 609
      Height = 205
      ColCount = 7
      FixedCols = 0
      RowCount = 2
      TabOrder = 0
      ColWidths = (
        106
        115
        125
        119
        137
        64
        64)
    end
  end
  object RadioGroup1: TRadioGroup
    Left = 4
    Top = 84
    Width = 621
    Height = 73
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1087#1086#1080#1089#1082#1072
    TabOrder = 3
  end
  object CheckBox1: TCheckBox
    Left = 28
    Top = 108
    Width = 189
    Height = 17
    Caption = #1048#1089#1082#1072#1090#1100' '#1090#1086#1083#1100#1082#1086' '#1089#1083#1086#1074#1086' '#1094#1077#1083#1080#1082#1086#1084
    TabOrder = 4
  end
  object CheckBox2: TCheckBox
    Left = 28
    Top = 132
    Width = 273
    Height = 17
    Caption = #1042#1099#1087#1086#1083#1085#1103#1102#1090#1089#1103' '#1086#1073#1072' '#1082#1088#1080#1090#1077#1088#1080#1103' '#1086#1076#1085#1086#1074#1088#1077#1084#1077#1085#1085#1086
    TabOrder = 5
  end
end
