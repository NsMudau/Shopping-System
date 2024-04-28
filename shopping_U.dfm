object frmshopping: Tfrmshopping
  Left = 0
  Top = 0
  Caption = 'Shopping system'
  ClientHeight = 478
  ClientWidth = 973
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 13
  object Label1: TLabel
    Left = 28
    Top = 46
    Width = 438
    Height = 13
    Caption = 
      'Item                        Size                         Price  ' +
      '                           Code                Quantity'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lstitems: TListBox
    Left = 25
    Top = 65
    Width = 489
    Height = 382
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    TabWidth = 50
  end
  object btnload: TButton
    Left = 28
    Top = 8
    Width = 81
    Height = 25
    Caption = 'Load items'
    TabOrder = 1
    OnClick = btnloadClick
  end
  object pnlscan: TPanel
    Left = 520
    Top = 65
    Width = 441
    Height = 382
    TabOrder = 2
    Visible = False
    object Label2: TLabel
      Left = 16
      Top = 134
      Width = 40
      Height = 23
      Caption = 'Cart'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lbltotal: TLabel
      Left = 255
      Top = 218
      Width = 131
      Height = 18
      Caption = 'Total amount: R 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lbltotalitems: TLabel
      Left = 255
      Top = 258
      Width = 102
      Height = 18
      Caption = 'Total items: 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblchange: TLabel
      Left = 255
      Top = 298
      Width = 74
      Height = 18
      Caption = 'Change: 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblmessage: TLabel
      Left = 16
      Top = 360
      Width = 65
      Height = 18
      Caption = 'message'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblsearch: TLabel
      Left = 16
      Top = 43
      Width = 5
      Height = 19
      Color = clGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object lstcart: TListBox
      Left = 17
      Top = 163
      Width = 216
      Height = 162
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ItemHeight = 13
      ParentFont = False
      TabOrder = 0
    end
    object btnscan: TButton
      Left = 16
      Top = 84
      Width = 145
      Height = 29
      Caption = 'Scan the selected item'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = btnscanClick
    end
    object btnpay: TButton
      Left = 248
      Top = 163
      Width = 137
      Height = 25
      Caption = 'Pay'
      TabOrder = 2
      OnClick = btnpayClick
    end
    object btnsearch: TButton
      Left = 16
      Top = 12
      Width = 129
      Height = 25
      Caption = 'Search item by Code'
      TabOrder = 3
      OnClick = btnsearchClick
    end
    object edtsearch: TEdit
      Left = 161
      Top = 9
      Width = 152
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
    end
    object rdgPaymentMethod: TRadioGroup
      Left = 248
      Top = 68
      Width = 137
      Height = 83
      Caption = 'Payment Method'
      Items.Strings = (
        'Cash'
        'Card')
      TabOrder = 5
    end
    object btnremove: TButton
      Left = 16
      Top = 331
      Width = 105
      Height = 25
      Caption = 'Remove Item'
      Enabled = False
      TabOrder = 6
      OnClick = btnremoveClick
    end
  end
  object btnmanage: TButton
    Left = 791
    Top = 8
    Width = 131
    Height = 25
    Caption = 'Management site'
    TabOrder = 3
    OnClick = btnmanageClick
  end
  object stbinfo: TStatusBar
    Left = 0
    Top = 459
    Width = 973
    Height = 19
    Panels = <
      item
        Width = 300
      end
      item
        Width = 300
      end>
  end
end
