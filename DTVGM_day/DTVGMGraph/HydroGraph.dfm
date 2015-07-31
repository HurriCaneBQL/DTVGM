object frmHydroGraph: TfrmHydroGraph
  Left = 153
  Top = 414
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'HydroGraph'
  ClientHeight = 255
  ClientWidth = 786
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 94
    Top = 10
    Width = 16
    Height = 13
    Caption = 'File'
    Visible = False
  end
  object Notebook1: TNotebook
    Left = 0
    Top = 3
    Width = 786
    Height = 249
    TabOrder = 5
    object TPage
      Left = 0
      Top = 0
      Caption = 'Discharge'
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 713
        Height = 249
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Text.Strings = (
          #38477#27700#65293#24452#27969#36807#31243#32447)
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMaximum = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.Maximum = 297
        LeftAxis.Title.Caption = 'Qobs-Qcal (m3/s)'
        LeftAxis.Title.Font.Charset = ANSI_CHARSET
        LeftAxis.Title.Font.Color = clFuchsia
        LeftAxis.Title.Font.Height = -12
        LeftAxis.Title.Font.Name = 'Times New Roman'
        LeftAxis.Title.Font.Style = []
        Legend.Alignment = laBottom
        RightAxis.Automatic = False
        RightAxis.AutomaticMaximum = False
        RightAxis.AutomaticMinimum = False
        RightAxis.Inverted = True
        RightAxis.Maximum = 87
        RightAxis.Title.Angle = 90
        RightAxis.Title.Caption = 'Rain-SoilMoisture (mm)'
        RightAxis.Title.Font.Charset = DEFAULT_CHARSET
        RightAxis.Title.Font.Color = clFuchsia
        RightAxis.Title.Font.Height = -11
        RightAxis.Title.Font.Name = 'Arial'
        RightAxis.Title.Font.Style = []
        View3D = False
        BorderStyle = bsSingle
        TabOrder = 0
        object Series_qobs: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clBlack
          Title = 'Series_Qobs'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = True
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_qcal: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Series_Qcal'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = True
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_P: TBarSeries
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clGreen
          Title = 'Series_Rain'
          VertAxis = aRightAxis
          BarBrush.Color = clWhite
          SideMargins = False
          XValues.DateTime = True
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_sm: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clBlue
          Title = 'Series_SoilMoisture'
          VertAxis = aRightAxis
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = True
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
    end
    object TPage
      Left = 0
      Top = 0
      Caption = 'Runoff'
      object Chart2: TChart
        Left = 0
        Top = 0
        Width = 785
        Height = 249
        BackWall.Brush.Color = clWhite
        Title.Text.Strings = (
          #22320#34920#24452#27969#65293#22320#19979#24452#27969#65293#24635#24452#27969#65293#33976#25955#21457)
        LeftAxis.Title.Caption = 'Runff (mm)'
        Legend.Alignment = laBottom
        RightAxis.LabelStyle = talValue
        RightAxis.Title.Angle = 90
        RightAxis.Title.Caption = 'ETa (mm)'
        View3D = False
        View3DOptions.Elevation = 315
        View3DOptions.Orthogonal = False
        View3DOptions.Perspective = 0
        View3DOptions.Rotation = 360
        BorderStyle = bsSingle
        TabOrder = 0
        object Series_Rd: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clBlack
          Title = 'Series_SurfaceRunoff'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_Rs: TLineSeries
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clBlue
          Title = 'Series_SubSurfaceRunoff'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psTriangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_R: TLineSeries
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clGreen
          Title = 'Series_Runoff'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psDownTriangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_ETa: TLineSeries
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Series_ETa'
          VertAxis = aRightAxis
          LinePen.Style = psDot
          Pointer.InflateMargins = True
          Pointer.Style = psCircle
          Pointer.Visible = True
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
    end
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 297
    Width = 745
    Height = 225
    ColCount = 7
    DefaultColWidth = 80
    DefaultRowHeight = 20
    FixedCols = 6
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing]
    TabOrder = 0
    Visible = False
  end
  object RadioGroup1: TRadioGroup
    Left = 448
    Top = 0
    Width = 281
    Height = 28
    TabOrder = 1
    Visible = False
  end
  object RadioButton1: TRadioButton
    Left = 456
    Top = 9
    Width = 121
    Height = 17
    Caption = #38477#27700#65293#24452#27969#36807#31243#32447
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Visible = False
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 592
    Top = 9
    Width = 113
    Height = 17
    Caption = #20135#27969#20998#37327
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Visible = False
    OnClick = RadioButton2Click
  end
  object BitBtn1: TBitBtn
    Left = 5
    Top = 3
    Width = 81
    Height = 24
    Caption = 'Load Data'
    TabOrder = 4
    Visible = False
    OnClick = BitBtn1Click
    Glyph.Data = {
      42020000424D4202000000000000420000002800000010000000100000000100
      1000030000000002000000000000000000000000000000000000007C0000E003
      00001F000000FF7FFF7FFF7FFF7FFF7F000000000000000000000000FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F000000000064607C407C637DE27CC96900000000
      FF7FFF7FFF7FFF7FFF7F00000A5800600074807CA07C647DC77DA97D646A6762
      0000FF7FFF7FFF7F00001050035C0564007C807CC07CA47DCB7DA67E467ECC6E
      8C620000FF7FFF7F00000F541060026C007CA07C237DCA7D877E687E4E7FC77E
      EC6A0000FF7F0000164418400E5C0E6805680170897144768D7A0A7FE87E2B7F
      2377E562000000001E3C1E401C4814400D5C265C00000000CC6E8976647F617F
      A37F8177000000003F2C1F2C3F2C1B48164C0000FF7FFF7F0000A066C06E4077
      60778077000000005F303F283F303F28DB380000FF7FFF7F0000404E8056C05E
      6073A077000000001F31FF341F351F3D1E39194200000000C02EA025203EE045
      A056A05A000000003A3D1F391F3D1F3DDF35FC39F5222C2F001F0013E021401E
      E045604A0000FF7F00007A451F46FF417F3A7E22521B8A2BC017401B2013C025
      202A0000FF7FFF7F0000184ADB3DDF357F3ABF165B37F21BE937C013C01AA00E
      40360000FF7FFF7FFF7F000078425A2E9E1ADE129B33F21FE93B801B00238032
      0000FF7FFF7FFF7FFF7FFF7F000000005A1EBD069C3BF523AA3F272B00000000
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F000000000000000000000000FF7FFF7F
      FF7FFF7FFF7F}
  end
end