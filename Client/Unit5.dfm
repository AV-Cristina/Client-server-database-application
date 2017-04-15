object Form5: TForm5
  Left = 289
  Top = 271
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1060#1080#1083#1100#1090#1088
  ClientHeight = 280
  ClientWidth = 438
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
    Left = 340
    Top = 248
    Width = 89
    Height = 21
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 240
    Top = 248
    Width = 89
    Height = 21
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 1
    OnClick = Button2Click
  end
  object GroupBox1: TGroupBox
    Left = 4
    Top = 4
    Width = 429
    Height = 77
    Caption = ' '#1050#1088#1080#1090#1077#1088#1080#1081' 1 '
    TabOrder = 2
    object Label1: TLabel
      Left = 20
      Top = 24
      Width = 58
      Height = 13
      Caption = #1048#1084#1103' '#1087#1086#1083#1103' 1'
    end
    object Label2: TLabel
      Left = 20
      Top = 52
      Width = 75
      Height = 13
      Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1087#1086#1083#1103
    end
    object Edit1: TEdit
      Left = 132
      Top = 48
      Width = 285
      Height = 21
      TabOrder = 0
    end
    object ComboBox1: TComboBox
      Left = 132
      Top = 16
      Width = 285
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 1
    end
  end
  object GroupBox2: TGroupBox
    Left = 4
    Top = 84
    Width = 429
    Height = 77
    Caption = ' '#1050#1088#1080#1090#1077#1088#1080#1081' 2 '
    TabOrder = 3
    object Label3: TLabel
      Left = 20
      Top = 24
      Width = 58
      Height = 13
      Caption = #1048#1084#1103' '#1087#1086#1083#1103' 2'
    end
    object Label4: TLabel
      Left = 20
      Top = 48
      Width = 75
      Height = 13
      Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1087#1086#1083#1103
    end
    object ComboBox2: TComboBox
      Left = 132
      Top = 16
      Width = 285
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 132
      Top = 44
      Width = 285
      Height = 21
      TabOrder = 1
    end
  end
  object RadioGroup1: TRadioGroup
    Left = 4
    Top = 168
    Width = 429
    Height = 65
    Caption = ' '#1059#1089#1083#1086#1074#1080#1077' '
    TabOrder = 4
  end
  object RadioButton1: TRadioButton
    Left = 24
    Top = 196
    Width = 161
    Height = 21
    Caption = #1042#1099#1087#1086#1083#1085#1103#1102#1090#1089#1103' '#1086#1073#1072' '#1082#1088#1080#1090#1077#1088#1080#1103
    TabOrder = 5
  end
  object RadioButton2: TRadioButton
    Left = 212
    Top = 196
    Width = 205
    Height = 21
    Caption = #1042#1099#1087#1086#1083#1085#1103#1077#1090#1089#1103' '#1093#1086#1090#1103' '#1073#1099' '#1086#1076#1080#1085' '#1082#1088#1080#1090#1077#1088#1080#1081
    TabOrder = 6
  end
end
