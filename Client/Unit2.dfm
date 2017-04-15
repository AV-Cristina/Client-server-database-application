object Form2: TForm2
  Left = 391
  Top = 268
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
  ClientHeight = 136
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
  object Label1: TLabel
    Left = 12
    Top = 28
    Width = 88
    Height = 13
    Caption = #1055#1086#1083#1077' '#1089#1086#1088#1090#1080#1088#1086#1074#1082#1080
  end
  object Label2: TLabel
    Left = 12
    Top = 60
    Width = 124
    Height = 13
    Caption = #1053#1072#1087#1088#1072#1083#1077#1085#1080#1077' '#1089#1086#1088#1090#1080#1088#1086#1074#1082#1080
  end
  object ComboBox1: TComboBox
    Left = 148
    Top = 20
    Width = 281
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 0
  end
  object ComboBox2: TComboBox
    Left = 148
    Top = 52
    Width = 281
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 1
    Items.Strings = (
      #1055#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102
      #1055#1086' '#1091#1073#1099#1074#1072#1085#1080#1102)
  end
  object Button1: TButton
    Left = 332
    Top = 100
    Width = 97
    Height = 25
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
end
