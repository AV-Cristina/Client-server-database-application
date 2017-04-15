object Form3: TForm3
  Left = 399
  Top = 281
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1079#1072#1087#1080#1089#1080
  ClientHeight = 315
  ClientWidth = 398
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 12
    Top = 144
    Width = 61
    Height = 13
    Caption = #1053#1072#1079#1085#1072#1095#1077#1085#1080#1077
  end
  object Label3: TLabel
    Left = 12
    Top = 176
    Width = 90
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1079#1072#1082#1072#1079#1095#1080#1082#1072
  end
  object Label4: TLabel
    Left = 12
    Top = 208
    Width = 168
    Height = 13
    Caption = #1057#1090#1077#1087#1077#1085#1100' '#1079#1072#1074#1077#1088#1096#1077#1085#1085#1086#1089#1090#1080' '#1087#1088#1086#1077#1082#1090#1072
  end
  object Label5: TLabel
    Left = 12
    Top = 240
    Width = 187
    Height = 13
    Caption = #1048#1089#1087#1086#1083#1100#1079#1091#1077#1084#1099#1077' '#1084#1086#1076#1091#1083#1080' / '#1073#1080#1073#1083#1080#1086#1090#1077#1082#1080
  end
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 183
    Height = 13
    Caption = #1055#1086#1083#1085#1086#1077' '#1080#1084#1103' '#1075#1083#1072#1074#1085#1086#1075#1086' '#1092#1072#1081#1083#1072' '#1087#1088#1077#1082#1090#1072
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 68
    Width = 397
    Height = 53
    Caption = ' '#1055#1077#1088#1080#1086#1076' '#1088#1072#1073#1086#1090#1099' '#1085#1072#1076' '#1087#1088#1086#1077#1082#1090#1086#1084' '
    TabOrder = 0
    object Label6: TLabel
      Left = 12
      Top = 24
      Width = 10
      Height = 13
      Caption = #1057' '
    end
    object Label17: TLabel
      Left = 124
      Top = 24
      Width = 14
      Height = 13
      Caption = #1055#1086
    end
    object DateTimePicker2: TDateTimePicker
      Left = 148
      Top = 20
      Width = 81
      Height = 21
      CalAlignment = dtaLeft
      Date = 40470.862328912
      Time = 40470.862328912
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 0
    end
  end
  object Edit5: TEdit
    Left = 236
    Top = 232
    Width = 149
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 308
    Top = 276
    Width = 77
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 32
    Width = 381
    Height = 21
    TabOrder = 3
  end
  object Edit3: TEdit
    Left = 236
    Top = 168
    Width = 149
    Height = 21
    TabOrder = 4
    OnKeyPress = Edit3KeyPress
  end
  object Edit4: TEdit
    Left = 236
    Top = 200
    Width = 149
    Height = 21
    TabOrder = 5
  end
  object Edit2: TEdit
    Left = 236
    Top = 136
    Width = 149
    Height = 21
    TabOrder = 6
  end
  object Button2: TButton
    Left = 356
    Top = 236
    Width = 25
    Height = 21
    Hint = #1042#1099#1073#1088#1072#1090#1100' '#1080#1079' '#1089#1091#1097#1077#1089#1090#1074#1091#1102#1097#1080#1093
    Caption = '...'
    TabOrder = 7
    OnClick = Button2Click
  end
  object DateTimePicker1: TDateTimePicker
    Left = 28
    Top = 88
    Width = 81
    Height = 21
    CalAlignment = dtaLeft
    Date = 40470.8600911458
    Time = 40470.8600911458
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 8
  end
end
