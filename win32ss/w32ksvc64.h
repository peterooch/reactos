    // SVC_(<NAME>, <ARG_COUNT>)
    //
    // Funcs order should match Windows 2003 Service Pack 2 x64 Free
    // Note: these MUST be indented for the ARM assembler!
    //
    SVC_(UserGetThreadState, 1)	//	 0x1000
    SVC_(UserPeekMessage, 5)	//	 0x1001
    SVC_(UserCallOneParam, 2)	//	 0x1002
    SVC_(UserGetKeyState, 1)	//	 0x1003
    SVC_(UserInvalidateRect, 3)	//	 0x1004
    SVC_(UserCallNoParam, 1)	//	 0x1005
    SVC_(UserGetMessage, 4)	//	 0x1006
    SVC_(UserMessageCall, 7)	//	 0x1007
    SVC_(GdiBitBlt, 11)	//	 0x1008
    SVC_(GdiGetCharSet, 1)	//	 0x1009
    SVC_(UserGetDC, 1)	//	 0x100a
    SVC_(GdiSelectBitmap, 2)	//	 0x100b
    SVC_(UserWaitMessage, 0)	//	 0x100c
    SVC_(UserTranslateMessage, 2)	//	 0x100d
    SVC_(UserPostMessage, 4)	//	 0x100e
    SVC_(UserQueryWindow, 2)	//	 0x100f
    SVC_(UserTranslateAccelerator, 3)	//	 0x1010
    SVC_(GdiFlush, 0)	//	 0x1011
    SVC_(UserRedrawWindow, 4)	//	 0x1012
    SVC_(UserWindowFromPoint, 2)	//	 0x1013
    SVC_(UserCallMsgFilter, 2)	//	 0x1014
    SVC_(UserValidateTimerCallback, 1)	//	 0x1015
    SVC_(UserBeginPaint, 2)	//	 0x1016
    SVC_(UserSetTimer, 4)	//	 0x1017
    SVC_(UserEndPaint, 2)	//	 0x1018
    SVC_(UserSetCursor, 1)	//	 0x1019
    SVC_(UserKillTimer, 2)	//	 0x101a
    SVC_(UserBuildHwndList, 7)	//	 0x101b
    SVC_(UserSelectPalette, 3)	//	 0x101c
    SVC_(UserCallNextHookEx, 4)	//	 0x101d
    SVC_(UserHideCaret, 1)	//	 0x101e
    SVC_(GdiIntersectClipRect, 5)	//	 0x101f
    SVC_(UserCallHwndLock, 2)	//	 0x1020
    SVC_(UserGetProcessWindowStation, 0)	//	 0x1021
    SVC_(GdiDeleteObjectApp, 1)	//	 0x1022
    SVC_(UserSetWindowPos, 7)	//	 0x1023
    SVC_(UserShowCaret, 1)	//	 0x1024
    SVC_(UserEndDeferWindowPosEx, 2)	//	 0x1025
    SVC_(UserCallHwndParamLock, 3)	//	 0x1026
    SVC_(UserVkKeyScanEx, 3)	//	 0x1027
    SVC_(GdiSetDIBitsToDeviceInternal, 16)	//	 0x1028
    SVC_(UserCallTwoParam, 3)	//	 0x1029
    SVC_(GdiGetRandomRgn, 3)	//	 0x102a
    SVC_(UserCopyAcceleratorTable, 3)	//	 0x102b
    SVC_(UserNotifyWinEvent, 4)	//	 0x102c
    SVC_(GdiExtSelectClipRgn, 3)	//	 0x102d
    SVC_(UserIsClipboardFormatAvailable, 1)	//	 0x102e
    SVC_(UserSetScrollInfo, 4)	//	 0x102f
    SVC_(GdiStretchBlt, 12)	//	 0x1030
    SVC_(UserCreateCaret, 4)	//	 0x1031
    SVC_(GdiRectVisible, 2)	//	 0x1032
    SVC_(GdiCombineRgn, 4)	//	 0x1033
    SVC_(GdiGetDCObject, 2)	//	 0x1034
    SVC_(UserDispatchMessage, 1)	//	 0x1035
    SVC_(UserRegisterWindowMessage, 1)	//	 0x1036
    SVC_(GdiExtTextOutW, 9)	//	 0x1037
    SVC_(GdiSelectFont, 2)	//	 0x1038
    SVC_(GdiRestoreDC, 2)	//	 0x1039
    SVC_(GdiSaveDC, 1)	//	 0x103a
    SVC_(UserGetForegroundWindow, 0)	//	 0x103b
    SVC_(UserShowScrollBar, 3)	//	 0x103c
    SVC_(UserFindExistingCursorIcon, 3)	//	 0x103d
    SVC_(GdiGetDCDword, 3)	//	 0x103e
    SVC_(GdiGetRegionData, 3)	//	 0x103f
    SVC_(GdiLineTo, 3)	//	 0x1040
    SVC_(UserSystemParametersInfo, 4)	//	 0x1041
    SVC_(GdiGetAppClipBox, 2)	//	 0x1042
    SVC_(UserGetAsyncKeyState, 1)	//	 0x1043
    SVC_(UserGetCPD, 3)	//	 0x1044
    SVC_(UserRemoveProp, 2)	//	 0x1045
    SVC_(GdiDoPalette, 6)	//	 0x1046
    SVC_(GdiPolyPolyDraw, 5)	//	 0x1047
    SVC_(UserSetCapture, 1)	//	 0x1048
    SVC_(UserEnumDisplayMonitors, 5) /* FIXME: 4 on XP/2k3 */	//	 0x1049
    SVC_(GdiCreateCompatibleBitmap, 3)	//	 0x104a
    SVC_(UserSetProp, 3)	//	 0x104b
    SVC_(GdiGetTextCharsetInfo, 3)	//	 0x104c
    SVC_(UserSBGetParms, 4)	//	 0x104d
    SVC_(UserGetIconInfo, 6)	//	 0x104e
    SVC_(UserExcludeUpdateRgn, 2)	//	 0x104f
    SVC_(UserSetFocus, 1)	//	 0x1050
    SVC_(GdiExtGetObjectW, 3)	//	 0x1051
    SVC_(UserDeferWindowPos, 8)	//	 0x1052
    SVC_(UserGetUpdateRect, 3)	//	 0x1053
    SVC_(GdiCreateCompatibleDC, 1)	//	 0x1054
    SVC_(UserGetClipboardSequenceNumber, 0)	//	 0x1055
    SVC_(GdiCreatePen, 4)	//	 0x1056
    SVC_(UserShowWindow, 2)	//	 0x1057
    SVC_(UserGetKeyboardLayoutList, 2)	//	 0x1058
    SVC_(GdiPatBlt, 6)	//	 0x1059
    SVC_(UserMapVirtualKeyEx, 4)	//	 0x105a
    SVC_(UserSetWindowLong, 4)	//	 0x105b
    SVC_(GdiHfontCreate, 5)	//	 0x105c
    SVC_(UserMoveWindow, 6)	//	 0x105d
    SVC_(UserPostThreadMessage, 4)	//	 0x105e
    SVC_(UserDrawIconEx, 11)	//	 0x105f
    SVC_(UserGetSystemMenu, 2)	//	 0x1060
    SVC_(GdiDrawStream, 3)	//	 0x1061
    SVC_(UserInternalGetWindowText, 3)	//	 0x1062
    SVC_(UserGetWindowDC, 1)	//	 0x1063
    SVC_(GdiD3dDrawPrimitives2, 7)	//	 0x1064
    SVC_(GdiInvertRgn, 2)	//	 0x1065
    SVC_(GdiGetRgnBox, 2)	//	 0x1066
    SVC_(GdiGetAndSetDCDword, 4)	//	 0x1067
    SVC_(GdiMaskBlt, 13)	//	 0x1068
    SVC_(GdiGetWidthTable, 7)	//	 0x1069
    SVC_(UserScrollDC, 7)	//	 0x106a
    SVC_(UserGetObjectInformation, 5)	//	 0x106b
    SVC_(GdiCreateBitmap, 5)	//	 0x106c
    SVC_(GdiConsoleTextOut, 4)	//	 0x106d
    SVC_(UserFindWindowEx, 5)	//	 0x106e
    SVC_(GdiPolyPatBlt, 5)	//	 0x106f
    SVC_(UserUnhookWindowsHookEx, 1)	//	 0x1070
    SVC_(GdiGetNearestColor, 2)	//	 0x1071
    SVC_(GdiTransformPoints, 5)	//	 0x1072
    SVC_(GdiGetDCPoint, 3)	//	 0x1073
    SVC_(UserCheckImeHotKey, 2)	//	 0x1074
    SVC_(GdiCreateDIBBrush, 6)	//	 0x1075
    SVC_(GdiGetTextMetricsW, 3)	//	 0x1076
    SVC_(UserCreateWindowEx, 15)	//	 0x1077
    SVC_(UserSetParent, 2)	//	 0x1078
    SVC_(UserGetKeyboardState, 1)	//	 0x1079
    SVC_(UserToUnicodeEx, 7)	//	 0x107a
    SVC_(UserGetControlBrush, 3)	//	 0x107b
    SVC_(UserGetClassName, 3)	//	 0x107c
    SVC_(GdiAlphaBlend, 12)	//	 0x107d
    SVC_(GdiDdBlt, 3)	//	 0x107e
    SVC_(GdiOffsetRgn, 3)	//	 0x107f
    SVC_(UserDefSetText, 2)	//	 0x1080
    SVC_(GdiGetTextFaceW, 4)	//	 0x1081
    SVC_(GdiStretchDIBitsInternal, 16)	//	 0x1082
    SVC_(UserSendInput, 3)	//	 0x1083
    SVC_(UserGetThreadDesktop, 2)	//	 0x1084
    SVC_(GdiCreateRectRgn, 4)	//	 0x1085
    SVC_(GdiGetDIBitsInternal, 9)	//	 0x1086
    SVC_(UserGetUpdateRgn, 3)	//	 0x1087
    SVC_(GdiDeleteClientObj, 1)	//	 0x1088
    SVC_(UserGetIconSize, 4)	//	 0x1089
    SVC_(UserFillWindow, 4)	//	 0x108a
    SVC_(GdiExtCreateRegion, 3)	//	 0x108b
    SVC_(GdiComputeXformCoefficients, 1)	//	 0x108c
    SVC_(UserSetWindowsHookEx, 6)	//	 0x108d
    SVC_(UserNotifyProcessCreate, 4)	//	 0x108e
    SVC_(GdiUnrealizeObject, 1)	//	 0x108f
    SVC_(UserGetTitleBarInfo, 2)	//	 0x1090
    SVC_(GdiRectangle, 5)	//	 0x1091
    SVC_(UserSetThreadDesktop, 1)	//	 0x1092
    SVC_(UserGetDCEx, 3)	//	 0x1093
    SVC_(UserGetScrollBarInfo, 3)	//	 0x1094
    SVC_(GdiGetTextExtent, 5)	//	 0x1095
    SVC_(UserSetWindowFNID, 2)	//	 0x1096
    SVC_(GdiSetLayout, 3)	//	 0x1097
    SVC_(UserCalcMenuBar, 5)	//	 0x1098
    SVC_(UserThunkedMenuItemInfo, 6)	//	 0x1099
    SVC_(GdiExcludeClipRect, 5)	//	 0x109a
    SVC_(GdiCreateDIBSection, 9)	//	 0x109b
    SVC_(GdiGetDCforBitmap, 1)	//	 0x109c
    SVC_(UserDestroyCursor, 2)	//	 0x109d
    SVC_(UserDestroyWindow, 1)	//	 0x109e
    SVC_(UserCallHwndParam, 3)	//	 0x109f
    SVC_(GdiCreateDIBitmapInternal, 11)	//	 0x10a0
    SVC_(UserOpenWindowStation, 2)	//	 0x10a1
    SVC_(GdiDdDeleteSurfaceObject, 1)	//	 0x10a2
    SVC_(GdiEnumFontClose, 1)	//	 0x10a3
    SVC_(GdiEnumFontOpen, 7)	//	 0x10a4
    SVC_(GdiEnumFontChunk, 5)	//	 0x10a5
    SVC_(GdiDdCanCreateSurface, 2)	//	 0x10a6
    SVC_(GdiDdCreateSurface, 8)	//	 0x10a7
    SVC_(UserSetCursorIconData, 4)	//	 0x10a8
    SVC_(GdiDdDestroySurface, 2)	//	 0x10a9
    SVC_(UserCloseDesktop, 1)	//	 0x10aa
    SVC_(UserOpenDesktop, 3)	//	 0x10ab
    SVC_(UserSetProcessWindowStation, 1)	//	 0x10ac
    SVC_(UserGetAtomName, 2)	//	 0x10ad
    SVC_(GdiDdResetVisrgn, 2)	//	 0x10ae
    SVC_(GdiExtCreatePen, 11)	//	 0x10af
    SVC_(GdiCreatePaletteInternal, 2)	//	 0x10b0
    SVC_(GdiSetBrushOrg, 4)	//	 0x10b1
    SVC_(UserBuildNameList, 4)	//	 0x10b2
    SVC_(GdiSetPixel, 4)	//	 0x10b3
    SVC_(UserRegisterClassExWOW, 7)	//	 0x10b4
    SVC_(GdiCreatePatternBrushInternal, 3)	//	 0x10b5
    SVC_(UserGetAncestor, 2)	//	 0x10b6
    SVC_(GdiGetOutlineTextMetricsInternalW, 4)	//	 0x10b7
    SVC_(GdiSetBitmapBits, 3)	//	 0x10b8
    SVC_(UserCloseWindowStation, 1)	//	 0x10b9
    SVC_(UserGetDoubleClickTime, 0)	//	 0x10ba
    SVC_(UserEnableScrollBar, 3)	//	 0x10bb
    SVC_(GdiCreateSolidBrush, 2)	//	 0x10bc
    SVC_(UserGetClassInfo, 5)	//	 0x10bd aka UserGetClassInfoEx
    SVC_(GdiCreateClientObj, 1)	//	 0x10be
    SVC_(UserUnregisterClass, 3)	//	 0x10bf
    SVC_(UserDeleteMenu, 3)	//	 0x10c0
    SVC_(GdiRectInRegion, 2)	//	 0x10c1
    SVC_(UserScrollWindowEx, 8)	//	 0x10c2
    SVC_(GdiGetPixel, 3)	//	 0x10c3
    SVC_(UserSetClassLong, 4)	//	 0x10c4
    SVC_(UserGetMenuBarInfo, 4)	//	 0x10c5
    SVC_(GdiDdCreateSurfaceEx, 3)	//	 0x10c6
    SVC_(GdiDdCreateSurfaceObject, 6)	//	 0x10c7
    SVC_(GdiGetNearestPaletteIndex, 2)	//	 0x10c8
    SVC_(GdiDdLockD3D, 2)	//	 0x10c9
    SVC_(GdiDdUnlockD3D, 2)	//	 0x10ca
    SVC_(GdiGetCharWidthW, 6)	//	 0x10cb
    SVC_(UserInvalidateRgn, 3)	//	 0x10cc
    SVC_(UserGetClipboardOwner, 0)	//	 0x10cd
    SVC_(UserSetWindowRgn, 3)	//	 0x10ce
    SVC_(UserBitBltSysBmp, 8)	//	 0x10cf
    SVC_(GdiGetCharWidthInfo, 2)	//	 0x10d0
    SVC_(UserValidateRect, 2)	//	 0x10d1
    SVC_(UserCloseClipboard, 0)	//	 0x10d2
    SVC_(UserOpenClipboard, 2)	//	 0x10d3
    SVC_(GdiGetStockObject, 1)	//	 0x10d4
    SVC_(UserSetClipboardData, 3)	//	 0x10d5
    SVC_(UserEnableMenuItem, 3)	//	 0x10d6
    SVC_(UserAlterWindowStyle, 3)	//	 0x10d7
    SVC_(GdiFillRgn, 3)	//	 0x10d8
    SVC_(UserGetWindowPlacement, 2)	//	 0x10d9
    SVC_(GdiModifyWorldTransform, 3)	//	 0x10da
    SVC_(GdiGetFontData, 5)	//	 0x10db
    SVC_(UserGetOpenClipboardWindow, 0)	//	 0x10dc
    SVC_(UserSetThreadState, 2)	//	 0x10dd
    SVC_(GdiOpenDCW, 7)	//	 0x10de
    SVC_(UserTrackMouseEvent, 1)	//	 0x10df
    SVC_(GdiGetTransform, 3)	//	 0x10e0
    SVC_(UserDestroyMenu, 1)	//	 0x10e1
    SVC_(GdiGetBitmapBits, 3)	//	 0x10e2
    SVC_(UserConsoleControl, 3)	//	 0x10e3
    SVC_(UserSetActiveWindow, 1)	//	 0x10e4
    SVC_(UserSetInformationThread, 4)	//	 0x10e5
    SVC_(UserSetWindowPlacement, 2)	//	 0x10e6
    SVC_(UserGetControlColor, 4)	//	 0x10e7
    SVC_(GdiSetMetaRgn, 1)	//	 0x10e8
    SVC_(GdiSetMiterLimit, 3)	//	 0x10e9
    SVC_(GdiSetVirtualResolution, 5)	//	 0x10ea
    SVC_(GdiGetRasterizerCaps, 2)	//	 0x10eb
    SVC_(UserSetWindowWord, 3)	//	 0x10ec
    SVC_(UserGetClipboardFormatName, 3)	//	 0x10ed
    SVC_(UserRealInternalGetMessage, 6)	//	 0x10ee
    SVC_(UserCreateLocalMemHandle, 4)	//	 0x10ef
    SVC_(UserAttachThreadInput, 3)	//	 0x10f0
    SVC_(GdiCreateHalftonePalette, 1)	//	 0x10f1
    SVC_(UserPaintMenuBar, 6)	//	 0x10f2
    SVC_(UserSetKeyboardState, 1)	//	 0x10f3
    SVC_(GdiCombineTransform, 3)	//	 0x10f4
    SVC_(UserCreateAcceleratorTable, 2)	//	 0x10f5
    SVC_(UserGetCursorFrameInfo, 4)	//	 0x10f6
    SVC_(UserGetAltTabInfo, 6)	//	 0x10f7
    SVC_(UserGetCaretBlinkTime, 0)	//	 0x10f8
    SVC_(GdiQueryFontAssocInfo, 1)	//	 0x10f9
    SVC_(UserProcessConnect, 3)	//	 0x10fa
    SVC_(UserEnumDisplayDevices, 4)	//	 0x10fb
    SVC_(UserEmptyClipboard, 0)	//	 0x10fc
    SVC_(UserGetClipboardData, 2)	//	 0x10fd
    SVC_(UserRemoveMenu, 3)	//	 0x10fe
    SVC_(GdiSetBoundsRect, 3)	//	 0x10ff
    SVC_(UserSetInformationProcess, 4)	//	 0x1100
    SVC_(GdiGetBitmapDimension, 2)	//	 0x1101
    SVC_(UserConvertMemHandle, 2)	//	 0x1102
    SVC_(UserDestroyAcceleratorTable, 1)	//	 0x1103
    SVC_(UserGetGUIThreadInfo, 2)	//	 0x1104
    SVC_(GdiCloseFigure, 1)	//	 0x1105
    SVC_(UserSetWindowsHookAW, 3)	//	 0x1106
    SVC_(UserSetMenuDefaultItem, 3)	//	 0x1107
    SVC_(UserCheckMenuItem, 3)	//	 0x1108
    SVC_(UserSetWinEventHook, 8)	//	 0x1109
    SVC_(UserUnhookWinEvent, 1)	//	 0x110a
    SVC_(GdiSetupPublicCFONT, 3)	//	 0x110b
    SVC_(UserLockWindowUpdate, 1)	//	 0x110c
    SVC_(UserSetSystemMenu, 2)	//	 0x110d
    SVC_(UserThunkedMenuInfo, 2)	//	 0x110e
    SVC_(GdiBeginPath, 1)	//	 0x110f
    SVC_(GdiEndPath, 1)	//	 0x1110
    SVC_(GdiFillPath, 1)	//	 0x1111
    SVC_(UserCallHwnd, 2)	//	 0x1112
    SVC_(UserDdeInitialize, 5)	//	 0x1113
    SVC_(UserModifyUserStartupInfoFlags, 2)	//	 0x1114
    SVC_(UserCountClipboardFormats, 0)	//	 0x1115
    SVC_(GdiAddFontMemResourceEx, 5)	//	 0x1116
    SVC_(GdiEqualRgn, 2)	//	 0x1117
    SVC_(GdiGetSystemPaletteUse, 1)	//	 0x1118
    SVC_(GdiRemoveFontMemResourceEx, 1)	//	 0x1119
    SVC_(UserEnumDisplaySettings, 4)	//	 0x111a
    SVC_(UserPaintDesktop, 1)	//	 0x111b
    SVC_(GdiExtEscape, 8)	//	 0x111c
    SVC_(GdiSetBitmapDimension, 4)	//	 0x111d
    SVC_(GdiSetFontEnumeration, 1)	//	 0x111e
    SVC_(UserChangeClipboardChain, 2)	//	 0x111f
    SVC_(UserResolveDesktop, 4)	//	 0x1120
    SVC_(UserSetClipboardViewer, 1)	//	 0x1121
    SVC_(UserShowWindowAsync, 2)	//	 0x1122
    SVC_(UserSetConsoleReserveKeys, 2)	//	 0x1123
    SVC_(GdiCreateColorSpace, 1)	//	 0x1124
    SVC_(GdiDeleteColorSpace, 1)	//	 0x1125
    SVC_(UserActivateKeyboardLayout, 2)	//	 0x1126
    SVC_(GdiAbortDoc, 1)	//	 0x1127
    SVC_(GdiAbortPath, 1)	//	 0x1128
    SVC_(GdiAddEmbFontToDC, 2)	//	 0x1129
    SVC_(GdiAddFontResourceW, 6)	//	 0x112a
    SVC_(GdiAddRemoteFontToDC, 4)	//	 0x112b
    SVC_(GdiAddRemoteMMInstanceToDC, 3)	//	 0x112c
    SVC_(GdiAngleArc, 6)	//	 0x112d
    SVC_(GdiAnyLinkedFonts, 0)	//	 0x112e
    SVC_(GdiArcInternal, 10)	//	 0x112f
    SVC_(GdiBRUSHOBJ_DeleteRbrush, 2)	//	 0x1130
    SVC_(GdiBRUSHOBJ_hGetColorTransform, 1)	//	 0x1131
    SVC_(GdiBRUSHOBJ_pvAllocRbrush, 2)	//	 0x1132
    SVC_(GdiBRUSHOBJ_pvGetRbrush, 1)	//	 0x1133
    SVC_(GdiBRUSHOBJ_ulGetBrushColor, 1)	//	 0x1134
    SVC_(GdiCLIPOBJ_bEnum, 3)	//	 0x1135
    SVC_(GdiCLIPOBJ_cEnumStart, 5)	//	 0x1136
    SVC_(GdiCLIPOBJ_ppoGetPath, 1)	//	 0x1137
    SVC_(GdiCancelDC, 1)	//	 0x1138
    SVC_(GdiChangeGhostFont, 2)	//	 0x1139
    SVC_(GdiCheckBitmapBits, 8)	//	 0x113a
    SVC_(GdiClearBitmapAttributes, 2)	//	 0x113b
    SVC_(GdiClearBrushAttributes, 2)	//	 0x113c
    SVC_(GdiColorCorrectPalette, 6)	//	 0x113d
    SVC_(GdiConvertMetafileRect, 2)	//	 0x113e
    SVC_(GdiCreateColorTransform, 8)	//	 0x113f
    SVC_(GdiCreateEllipticRgn, 4)	//	 0x1140
    SVC_(GdiCreateHatchBrushInternal, 3)	//	 0x1141
    SVC_(GdiCreateMetafileDC, 1)	//	 0x1142
    SVC_(GdiCreateRoundRectRgn, 6)	//	 0x1143
    SVC_(GdiCreateServerMetaFile, 6)	//	 0x1144
    SVC_(GdiD3dContextCreate, 4)	//	 0x1145
    SVC_(GdiD3dContextDestroy, 1)	//	 0x1146
    SVC_(GdiD3dContextDestroyAll, 1)	//	 0x1147
    SVC_(GdiD3dValidateTextureStageState, 1)	//	 0x1148
    SVC_(GdiDdAddAttachedSurface, 3)	//	 0x1149
    SVC_(GdiDdAlphaBlt, 3)	//	 0x114a
    SVC_(GdiDdAttachSurface, 2)	//	 0x114b
    SVC_(GdiDdBeginMoCompFrame, 2)	//	 0x114c
    SVC_(GdiDdCanCreateD3DBuffer, 2)	//	 0x114d
    SVC_(GdiDdColorControl, 2)	//	 0x114e
    SVC_(GdiDdCreateD3DBuffer, 8)	//	 0x114f
    SVC_(GdiDdCreateDirectDrawObject, 1)	//	 0x1150
    SVC_(GdiDdCreateMoComp, 2)	//	 0x1151
    SVC_(GdiDdDeleteDirectDrawObject, 1)	//	 0x1152
    SVC_(GdiDdDestroyD3DBuffer, 1)	//	 0x1153
    SVC_(GdiDdDestroyMoComp, 2)	//	 0x1154
    SVC_(GdiDdEndMoCompFrame, 2)	//	 0x1155
    SVC_(GdiDdFlip, 5)	//	 0x1156
    SVC_(GdiDdFlipToGDISurface, 2)	//	 0x1157
    SVC_(GdiDdGetAvailDriverMemory, 2)	//	 0x1158
    SVC_(GdiDdGetBltStatus, 2)	//	 0x1159
    SVC_(GdiDdGetDC, 2)	//	 0x115a
    SVC_(GdiDdGetDriverInfo, 2)	//	 0x115b
    SVC_(GdiDdGetDriverState, 1)	//	 0x115c
    SVC_(GdiDdGetDxHandle, 3)	//	 0x115d
    SVC_(GdiDdGetFlipStatus, 2)	//	 0x115e
    SVC_(GdiDdGetInternalMoCompInfo, 2)	//	 0x115f
    SVC_(GdiDdGetMoCompBuffInfo, 2)	//	 0x1160
    SVC_(GdiDdGetMoCompFormats, 2)	//	 0x1161
    SVC_(GdiDdGetMoCompGuids, 2)	//	 0x1162
    SVC_(GdiDdGetScanLine, 2)	//	 0x1163
    SVC_(GdiDdLock, 3)	//	 0x1164
    SVC_(GdiDdQueryDirectDrawObject, 11)	//	 0x1165
    SVC_(GdiDdQueryMoCompStatus, 2)	//	 0x1166
    SVC_(GdiDdReenableDirectDrawObject, 2)	//	 0x1167
    SVC_(GdiDdReleaseDC, 1)	//	 0x1168
    SVC_(GdiDdRenderMoComp, 2)	//	 0x1169
    SVC_(GdiDdSetColorKey, 2)	//	 0x116a
    SVC_(GdiDdSetExclusiveMode, 2)	//	 0x116b
    SVC_(GdiDdSetGammaRamp, 3)	//	 0x116c
    SVC_(GdiDdSetOverlayPosition, 3)	//	 0x116d
    SVC_(GdiDdUnattachSurface, 2)	//	 0x116e
    SVC_(GdiDdUnlock, 2)	//	 0x116f
    SVC_(GdiDdUpdateOverlay, 3)	//	 0x1170
    SVC_(GdiDdWaitForVerticalBlank, 2)	//	 0x1171
    SVC_(GdiDeleteColorTransform, 2)	//	 0x1172
    SVC_(GdiDescribePixelFormat, 4)	//	 0x1173
    SVC_(GdiDoBanding, 4)	//	 0x1174
    SVC_(GdiDrawEscape, 4)	//	 0x1175
    SVC_(GdiDvpAcquireNotification, 3)	//	 0x1176
    SVC_(GdiDvpCanCreateVideoPort, 2)	//	 0x1177
    SVC_(GdiDvpColorControl, 2)	//	 0x1178
    SVC_(GdiDvpCreateVideoPort, 2)	//	 0x1179
    SVC_(GdiDvpDestroyVideoPort, 2)	//	 0x117a
    SVC_(GdiDvpFlipVideoPort, 4)	//	 0x117b
    SVC_(GdiDvpGetVideoPortBandwidth, 2)	//	 0x117c
    SVC_(GdiDvpGetVideoPortConnectInfo, 2)	//	 0x117d
    SVC_(GdiDvpGetVideoPortField, 2)	//	 0x117e
    SVC_(GdiDvpGetVideoPortFlipStatus, 2)	//	 0x117f
    SVC_(GdiDvpGetVideoPortInputFormats, 2)	//	 0x1180
    SVC_(GdiDvpGetVideoPortLine, 2)	//	 0x1181
    SVC_(GdiDvpGetVideoPortOutputFormats, 2)	//	 0x1182
    SVC_(GdiDvpGetVideoSignalStatus, 2)	//	 0x1183
    SVC_(GdiDvpReleaseNotification, 2)	//	 0x1184
    SVC_(GdiDvpUpdateVideoPort, 4)	//	 0x1185
    SVC_(GdiDvpWaitForVideoPortSync, 2)	//	 0x1186
    SVC_(GdiDxgGenericThunk, 6)	//	 0x1187
    SVC_(GdiEllipse, 5)	//	 0x1188
    SVC_(GdiEnableEudc, 1)	//	 0x1189
    SVC_(GdiEndDoc, 1)	//	 0x118a
    SVC_(GdiEndPage, 1)	//	 0x118b
    SVC_(GdiEngAlphaBlend, 7)	//	 0x118c
    SVC_(GdiEngAssociateSurface, 3)	//	 0x118d
    SVC_(GdiEngBitBlt, 11)	//	 0x118e
    SVC_(GdiEngCheckAbort, 1)	//	 0x118f
    SVC_(GdiEngComputeGlyphSet, 3)	//	 0x1190
    SVC_(GdiEngCopyBits, 6)	//	 0x1191
    SVC_(GdiEngCreateBitmap, 6)	//	 0x1192
    SVC_(GdiEngCreateClip, 0)	//	 0x1193
    SVC_(GdiEngCreateDeviceBitmap, 4)	//	 0x1194
    SVC_(GdiEngCreateDeviceSurface, 4)	//	 0x1195
    SVC_(GdiEngCreatePalette, 6)	//	 0x1196
    SVC_(GdiEngDeleteClip, 1)	//	 0x1197
    SVC_(GdiEngDeletePalette, 1)	//	 0x1198
    SVC_(GdiEngDeletePath, 1)	//	 0x1199
    SVC_(GdiEngDeleteSurface, 1)	//	 0x119a
    SVC_(GdiEngEraseSurface, 3)	//	 0x119b
    SVC_(GdiEngFillPath, 7)	//	 0x119c
    SVC_(GdiEngGradientFill, 10)	//	 0x119d
    SVC_(GdiEngLineTo, 9)	//	 0x119e
    SVC_(GdiEngLockSurface, 1)	//	 0x119f
    SVC_(GdiEngMarkBandingSurface, 1)	//	 0x11a0
    SVC_(GdiEngPaint, 5)	//	 0x11a1
    SVC_(GdiEngPlgBlt, 11)	//	 0x11a2
    SVC_(GdiEngStretchBlt, 11)	//	 0x11a3
    SVC_(GdiEngStretchBltROP, 13)	//	 0x11a4
    SVC_(GdiEngStrokeAndFillPath, 10)	//	 0x11a5
    SVC_(GdiEngStrokePath, 8)	//	 0x11a6
    SVC_(GdiEngTextOut, 10)	//	 0x11a7
    SVC_(GdiEngTransparentBlt, 8)	//	 0x11a8
    SVC_(GdiEngUnlockSurface, 1)	//	 0x11a9
    SVC_(GdiEnumObjects, 4)	//	 0x11aa
    SVC_(GdiEudcLoadUnloadLink, 7)	//	 0x11ab
    SVC_(GdiExtFloodFill, 5)	//	 0x11ac
    SVC_(GdiFONTOBJ_cGetAllGlyphHandles, 2)	//	 0x11ad
    SVC_(GdiFONTOBJ_cGetGlyphs, 5)	//	 0x11ae
    SVC_(GdiFONTOBJ_pQueryGlyphAttrs, 2)	//	 0x11af
    SVC_(GdiFONTOBJ_pfdg, 1)	//	 0x11b0
    SVC_(GdiFONTOBJ_pifi, 1)	//	 0x11b1
    SVC_(GdiFONTOBJ_pvTrueTypeFontFile, 2)	//	 0x11b2
    SVC_(GdiFONTOBJ_pxoGetXform, 1)	//	 0x11b3
    SVC_(GdiFONTOBJ_vGetInfo, 3)	//	 0x11b4
    SVC_(GdiFlattenPath, 1)	//	 0x11b5
    SVC_(GdiFontIsLinked, 1)	//	 0x11b6
    SVC_(GdiForceUFIMapping, 2)	//	 0x11b7
    SVC_(GdiFrameRgn, 5)	//	 0x11b8
    SVC_(GdiFullscreenControl, 5)	//	 0x11b9
    SVC_(GdiGetBoundsRect, 3)	//	 0x11ba
    SVC_(GdiGetCharABCWidthsW, 6)	//	 0x11bb
    SVC_(GdiGetCharacterPlacementW, 6)	//	 0x11bc
    SVC_(GdiGetColorAdjustment, 2)	//	 0x11bd
    SVC_(GdiGetColorSpaceforBitmap, 1)	//	 0x11be
    SVC_(GdiGetDeviceCaps, 2)	//	 0x11bf
    SVC_(GdiGetDeviceCapsAll, 2)	//	 0x11c0
    SVC_(GdiGetDeviceGammaRamp, 2)	//	 0x11c1
    SVC_(GdiGetDeviceWidth, 1)	//	 0x11c2
    SVC_(GdiGetDhpdev, 1)	//	 0x11c3
    SVC_(GdiGetETM, 2)	//	 0x11c4
    SVC_(GdiGetEmbUFI, 7)	//	 0x11c5
    SVC_(GdiGetEmbedFonts, 0)	//	 0x11c6
    SVC_(GdiGetEudcTimeStampEx, 3)	//	 0x11c7
    SVC_(GdiGetFontResourceInfoInternalW, 7)	//	 0x11c8
    SVC_(GdiGetFontUnicodeRanges, 2)	//	 0x11c9
    SVC_(GdiGetGlyphIndicesW, 5)	//	 0x11ca
    SVC_(GdiGetGlyphIndicesWInternal, 6)	//	 0x11cb
    SVC_(GdiGetGlyphOutline, 8)	//	 0x11cc
    SVC_(GdiGetKerningPairs, 3)	//	 0x11cd
    SVC_(GdiGetLinkedUFIs, 3)	//	 0x11ce
    SVC_(GdiGetMiterLimit, 2)	//	 0x11cf
    SVC_(GdiGetMonitorID, 3)	//	 0x11d0
    SVC_(GdiGetObjectBitmapHandle, 2)	//	 0x11d1
    SVC_(GdiGetPath, 4)	//	 0x11d2
    SVC_(GdiGetPerBandInfo, 2)	//	 0x11d3
    SVC_(GdiGetRealizationInfo, 3)	//	 0x11d4
    SVC_(GdiGetServerMetaFileBits, 7)	//	 0x11d5
    SVC_(GdiGetSpoolMessage, 4)	//	 0x11d6
    SVC_(GdiGetStats, 5)	//	 0x11d7
    SVC_(GdiGetStringBitmapW, 5)	//	 0x11d8
    SVC_(GdiGetTextExtentExW, 8)	//	 0x11d9
    SVC_(GdiGetUFI, 6)	//	 0x11da
    SVC_(GdiGetUFIPathname, 10)	//	 0x11db
    SVC_(GdiGradientFill, 6)	//	 0x11dc
    SVC_(GdiHT_Get8BPPFormatPalette, 4)	//	 0x11dd
    SVC_(GdiHT_Get8BPPMaskPalette, 6)	//	 0x11de
    SVC_(GdiIcmBrushInfo, 8)	//	 0x11df
    SVC_(GdiInit, 0)	//	 0x11e0
    SVC_(GdiInitSpool, 0)	//	 0x11e1
    SVC_(GdiMakeFontDir, 5)	//	 0x11e2
    SVC_(GdiMakeInfoDC, 2)	//	 0x11e3
    SVC_(GdiMakeObjectUnXferable, 0)	//	 0x11e4
    SVC_(GdiMakeObjectXferable, 2)	//	 0x11e5
    SVC_(GdiMirrorWindowOrg, 1)	//	 0x11e6
    SVC_(GdiMonoBitmap, 1)	//	 0x11e7
    SVC_(GdiMoveTo, 4)	//	 0x11e8
    SVC_(GdiOffsetClipRgn, 3)	//	 0x11e9
    SVC_(GdiPATHOBJ_bEnum, 2)	//	 0x11ea
    SVC_(GdiPATHOBJ_bEnumClipLines, 3)	//	 0x11eb
    SVC_(GdiPATHOBJ_vEnumStart, 1)	//	 0x11ec
    SVC_(GdiPATHOBJ_vEnumStartClipLines, 4)	//	 0x11ed
    SVC_(GdiPATHOBJ_vGetBounds, 2)	//	 0x11ee
    SVC_(GdiPathToRegion, 1)	//	 0x11ef
    SVC_(GdiPlgBlt, 11)	//	 0x11f0
    SVC_(GdiPolyDraw, 4)	//	 0x11f1
    SVC_(GdiPolyTextOutW, 4)	//	 0x11f2
    SVC_(GdiPtInRegion, 3)	//	 0x11f3
    SVC_(GdiPtVisible, 3)	//	 0x11f4
    SVC_(GdiQueryFonts, 3)	//	 0x11f5
    SVC_(GdiRemoveFontResourceW, 6)	//	 0x11f6
    SVC_(GdiRemoveMergeFont, 2)	//	 0x11f7
    SVC_(GdiResetDC, 5)	//	 0x11f8
    SVC_(GdiResizePalette, 2)	//	 0x11f9
    SVC_(GdiRoundRect, 7)	//	 0x11fa
    SVC_(GdiSTROBJ_bEnum, 3)	//	 0x11fb
    SVC_(GdiSTROBJ_bEnumPositionsOnly, 3)	//	 0x11fc
    SVC_(GdiSTROBJ_bGetAdvanceWidths, 4)	//	 0x11fd
    SVC_(GdiSTROBJ_dwGetCodePage, 1)	//	 0x11fe
    SVC_(GdiSTROBJ_vEnumStart, 1)	//	 0x11ff
    SVC_(GdiScaleViewportExtEx, 6)	//	 0x1200
    SVC_(GdiScaleWindowExtEx, 6)	//	 0x1201
    SVC_(GdiSelectBrush, 2)	//	 0x1202
    SVC_(GdiSelectClipPath, 2)	//	 0x1203
    SVC_(GdiSelectPen, 2)	//	 0x1204
    SVC_(GdiSetBitmapAttributes, 2)	//	 0x1205
    SVC_(GdiSetBrushAttributes, 2)	//	 0x1206
    SVC_(GdiSetColorAdjustment, 2)	//	 0x1207
    SVC_(GdiSetColorSpace, 2)	//	 0x1208
    SVC_(GdiSetDeviceGammaRamp, 2)	//	 0x1209
    SVC_(GdiSetFontXform, 3)	//	 0x120a
    SVC_(GdiSetIcmMode, 3)	//	 0x120b
    SVC_(GdiSetLinkedUFIs, 3)	//	 0x120c
    SVC_(GdiSetMagicColors, 3)	//	 0x120d
    SVC_(GdiSetPUMPDOBJ, 4)	//	 0x120e
    SVC_(GdiSetPixelFormat, 2)	//	 0x120f
    SVC_(GdiSetRectRgn, 5)	//	 0x1210
    SVC_(GdiSetSizeDevice, 3)	//	 0x1211
    SVC_(GdiSetSystemPaletteUse, 2)	//	 0x1212
    SVC_(GdiSetTextJustification, 3)	//	 0x1213
    SVC_(GdiStartDoc, 4)	//	 0x1214
    SVC_(GdiStartPage, 1)	//	 0x1215
    SVC_(GdiStrokeAndFillPath, 1)	//	 0x1216
    SVC_(GdiStrokePath, 1)	//	 0x1217
    SVC_(GdiSwapBuffers, 1)	//	 0x1218
    SVC_(GdiTransparentBlt, 11)	//	 0x1219
    SVC_(GdiUMPDEngFreeUserMem, 1)	//	 0x121a
    SVC_(GdiUnloadPrinterDriver, 2)	//	 0x121b
    SVC_(GdiUnmapMemFont, 1)	//	 0x121c
    SVC_(GdiUpdateColors, 1)	//	 0x121d
    SVC_(GdiUpdateTransform, 1)	//	 0x121e
    SVC_(GdiWidenPath, 1)	//	 0x121f
    SVC_(GdiXFORMOBJ_bApplyXform, 5)	//	 0x1220
    SVC_(GdiXFORMOBJ_iGetXform, 2)	//	 0x1221
    SVC_(GdiXLATEOBJ_cGetPalette, 4)	//	 0x1222
    SVC_(GdiXLATEOBJ_hGetColorTransform, 1)	//	 0x1223
    SVC_(GdiXLATEOBJ_iXlate, 2)	//	 0x1224
    SVC_(UserAssociateInputContext, 3)	//	 0x1225
    SVC_(UserBlockInput, 1)	//	 0x1226
    SVC_(UserBuildHimcList, 4)	//	 0x1227
    SVC_(UserBuildPropList, 4)	//	 0x1228
    SVC_(UserCallHwndOpt, 2)	//	 0x1229
    SVC_(UserChangeDisplaySettings, 4)	//	 0x122a
    SVC_(UserChildWindowFromPointEx, 4)	//	 0x122b
    SVC_(UserClipCursor, 1)	//	 0x122c
    SVC_(UserCreateDesktop, 5)	//	 0x122d
    SVC_(UserCreateInputContext, 1)	//	 0x122e
    SVC_(UserCreateWindowStation, 7)	//	 0x122f
    SVC_(UserCtxDisplayIOCtl, 3)	//	 0x1230
    SVC_(UserDdeGetQualityOfService, 3)	//	 0x1231
    SVC_(UserDdeSetQualityOfService, 3)	//	 0x1232
    SVC_(UserDestroyInputContext, 1)	//	 0x1233
    SVC_(UserDisableThreadIme, 1)	//	 0x1234
    SVC_(UserDragDetect, 3)	//	 0x1235
    SVC_(UserDragObject, 5)	//	 0x1236
    SVC_(UserDrawAnimatedRects, 4)	//	 0x1237
    SVC_(UserDrawCaption, 4)	//	 0x1238
    SVC_(UserDrawCaptionTemp, 7)	//	 0x1239
    SVC_(UserDrawMenuBarTemp, 5)	//	 0x123a
    SVC_(UserEndMenu, 0)	//	 0x123b
    SVC_(UserEvent, 1)	//	 0x123c
    SVC_(UserFlashWindowEx, 1)	//	 0x123d
    SVC_(UserGetAppImeLevel, 1)	//	 0x123e
    SVC_(UserGetCaretPos, 1)	//	 0x123f
    SVC_(UserGetClipCursor, 1)	//	 0x1240
    SVC_(UserGetClipboardViewer, 0)	//	 0x1241
    SVC_(UserGetComboBoxInfo, 2)	//	 0x1242
    SVC_(UserGetCursorInfo, 1)	//	 0x1243
    SVC_(UserGetGuiResources, 2)	//	 0x1244
    SVC_(UserGetImeHotKey, 4)	//	 0x1245
    SVC_(UserGetImeInfoEx, 2)	//	 0x1246
    SVC_(UserGetInternalWindowPos, 3)	//	 0x1247
    SVC_(UserGetKeyNameText, 3)	//	 0x1248
    SVC_(UserGetKeyboardLayoutName, 1)	//	 0x1249
    SVC_(UserGetLayeredWindowAttributes, 4)	//	 0x124a
    SVC_(UserGetListBoxInfo, 1)	//	 0x124b
    SVC_(UserGetMenuIndex, 2)	//	 0x124c
    SVC_(UserGetMenuItemRect, 4)	//	 0x124d
    SVC_(UserGetMouseMovePointsEx, 5)	//	 0x124e
    SVC_(UserGetPriorityClipboardFormat, 2)	//	 0x124f
    SVC_(UserGetRawInputBuffer, 3)	//	 0x1250
    SVC_(UserGetRawInputData, 5)	//	 0x1251
    SVC_(UserGetRawInputDeviceInfo, 4)	//	 0x1252
    SVC_(UserGetRawInputDeviceList, 3)	//	 0x1253
    SVC_(UserGetRegisteredRawInputDevices, 3)	//	 0x1254
    SVC_(UserGetWOWClass, 2)	//	 0x1255
    SVC_(UserHardErrorControl, 3)	//	 0x1256
    SVC_(UserHiliteMenuItem, 4)	//	 0x1257
    SVC_(UserImpersonateDdeClientWindow, 2)	//	 0x1258
    SVC_(UserInitTask, 12)	//	 0x1259
    SVC_(UserInitialize, 3)	//	 0x125a
    SVC_(UserInitializeClientPfnArrays, 4)	//	 0x125b
    SVC_(UserLoadKeyboardLayoutEx, 7)	//	 0x125c
    SVC_(UserLockWindowStation, 1)	//	 0x125d
    SVC_(UserLockWorkStation, 0)	//	 0x125e
    SVC_(UserMNDragLeave, 0)	//	 0x125f
    SVC_(UserMNDragOver, 2)	//	 0x1260
    SVC_(UserMenuItemFromPoint, 4)	//	 0x1261
    SVC_(UserMinMaximize, 3)	//	 0x1262
    SVC_(UserNotifyIMEStatus, 3)	//	 0x1263
    SVC_(UserOpenInputDesktop, 3)	//	 0x1264
    SVC_(UserPrintWindow, 3)	//	 0x1265
    SVC_(UserQueryInformationThread, 4)	//	 0x1266
    SVC_(UserQueryInputContext, 2)	//	 0x1267
    SVC_(UserQuerySendMessage, 1)	//	 0x1268
    SVC_(UserRealChildWindowFromPoint, 3)	//	 0x1269
    SVC_(UserRealWaitMessageEx, 2)	//	 0x126a
    SVC_(UserRegisterHotKey, 4)	//	 0x126b
    SVC_(UserRegisterRawInputDevices, 3)	//	 0x126c
    SVC_(UserRegisterTasklist, 1)	//	 0x126d
    SVC_(UserRegisterUserApiHook, 4)	//	 0x126e
    SVC_(UserRemoteConnect, 3)	//	 0x126f
    SVC_(UserRemoteRedrawRectangle, 4)	//	 0x1270
    SVC_(UserRemoteRedrawScreen, 0)	//	 0x1271
    SVC_(UserRemoteStopScreenUpdates, 0)	//	 0x1272
    SVC_(UserResolveDesktopForWOW, 1)	//	 0x1273
    SVC_(UserSetAppImeLevel, 2)	//	 0x1274
    SVC_(UserSetClassWord, 3)	//	 0x1275
    SVC_(UserSetCursorContents, 2)	//	 0x1276
    SVC_(UserSetImeHotKey, 5)	//	 0x1277
    SVC_(UserSetImeInfoEx, 1)	//	 0x1278
    SVC_(UserSetImeOwnerWindow, 2)	//	 0x1279
    SVC_(UserSetInternalWindowPos, 4)	//	 0x127a
    SVC_(UserSetLayeredWindowAttributes, 4)	//	 0x127b
    SVC_(UserSetLogonNotifyWindow, 1)	//	 0x127c
    SVC_(UserSetMenu, 3)	//	 0x127d
    SVC_(UserSetMenuContextHelpId, 2)	//	 0x127e
    SVC_(UserSetMenuFlagRtoL, 1)	//	 0x127f
    SVC_(UserSetObjectInformation, 4)	//	 0x1280
    SVC_(UserSetShellWindowEx, 2)	//	 0x1281
    SVC_(UserSetSysColors, 4)	//	 0x1282
    SVC_(UserSetSystemCursor, 2)	//	 0x1283
    SVC_(UserSetSystemTimer, 4)	//	 0x1284
    SVC_(UserSetThreadLayoutHandles, 2)	//	 0x1285
    SVC_(UserSetWindowStationUser, 4)	//	 0x1286
    SVC_(UserSoundSentry, 0)	//	 0x1287
    SVC_(UserSwitchDesktop, 1)	//	 0x1288
    SVC_(UserTestForInteractiveUser, 1)	//	 0x1289
    SVC_(UserTrackPopupMenuEx, 6)	//	 0x128a
    SVC_(UserUnloadKeyboardLayout, 1)	//	 0x128b
    SVC_(UserUnlockWindowStation, 1)	//	 0x128c
    SVC_(UserUnregisterHotKey, 2)	//	 0x128d
    SVC_(UserUnregisterUserApiHook, 0)	//	 0x128e
    SVC_(UserUpdateInputContext, 3)	//	 0x128f
    SVC_(UserUpdateInstance, 3)	//	 0x1290
    SVC_(UserUpdateLayeredWindow, 10)	//	 0x1291
    SVC_(UserUpdatePerUserSystemParameters, 2)	//	 0x1292
    SVC_(UserUserHandleGrantAccess, 3)	//	 0x1293
    SVC_(UserValidateHandleSecure, 1)	//	 0x1294
    SVC_(UserWaitForInputIdle, 3)	//	 0x1295
    SVC_(UserWaitForMsgAndEvent, 1)	//	 0x1296
    SVC_(UserSetClassLongPtr, 4)	//	 0x1297
    SVC_(UserSetWindowLongPtr, 4)	//	 0x1298
    SVC_(UserWin32PoolAllocationStats, 6)	//	 0x1299
    SVC_(UserYieldTask, 0)	//	 0x129a
    SVC_(DxEngGetRedirectionBitmap, 1)	//
    SVC_(GdiDdDDICreateDCFromMemory, 1)	//
    SVC_(GdiDdDDIDestroyDCFromMemory, 1)	//
    SVC_(GdiGetFontFamilyInfo, 4)	//
    SVC_(GdiOffsetViewportOrgEx, 4)	//
    SVC_(GdiOffsetWindowOrgEx, 4)	//
    SVC_(GdiSetViewportOrgEx, 4)	//
    SVC_(GdiSetWindowOrgEx, 4)	//
    SVC_(UserDbgWin32HeapFail, 2)	//
    SVC_(UserDbgWin32HeapStat, 2)	//
    SVC_(UserGetMonitorInfo, 2)	//
    SVC_(UserMonitorFromPoint, 3)	//
    SVC_(UserMonitorFromRect, 2)	//
    SVC_(UserMonitorFromWindow, 2)	//
    SVC_(UserSetDbgTag, 2)	//
    SVC_(UserSetDbgTagCount, 1)	//
    SVC_(UserSetRipFlags, 1)	//
    SVC_(UserSetScrollBarInfo, 3)	//
// ReactOS Display Driver Model
    SVC_(GdiDdDDICheckExclusiveOwnership, 0)
    SVC_(GdiDdDDICreateAllocation, 1)
    SVC_(GdiDdDDICheckMonitorPowerState, 1)
    SVC_(GdiDdDDICheckOcclusion, 1)
    SVC_(GdiDdDDICloseAdapter, 1)
    SVC_(GdiDdDDICreateContext, 1)
    SVC_(GdiDdDDICreateDevice, 1)
    SVC_(GdiDdDDICreateOverlay, 1)
    SVC_(GdiDdDDICreateSynchronizationObject, 1)
    SVC_(GdiDdDDIWaitForVerticalBlankEvent, 1)
    SVC_(GdiDdDDIWaitForIdle, 1)
    SVC_(GdiDdDDIUpdateOverlay, 1)
    SVC_(GdiDdDDIUnlock, 1)
    SVC_(GdiDdDDIDestroyAllocation, 1)
    SVC_(GdiDdDDIDestroyContext, 1)
    SVC_(GdiDdDDIDestroyDevice, 1)
    SVC_(GdiDdDDIDestroyOverlay, 1)
    SVC_(GdiDdDDIDestroySynchronizationObject, 1)
    SVC_(GdiDdDDIEscape, 1)
    SVC_(GdiDdDDIFlipOverlay, 1)
    SVC_(GdiDdDDIGetContextSchedulingPriority, 1)
    SVC_(GdiDdDDIGetDeviceState, 1)
    SVC_(GdiDdDDIGetDisplayModeList, 1)
    SVC_(GdiDdDDIGetMultisampleMethodList, 1)
    SVC_(GdiDdDDIGetPresentHistory, 1)
    SVC_(GdiDdDDIGetProcessSchedulingPriorityClass, 2)
    SVC_(GdiDdDDIGetRuntimeData, 1)
    SVC_(GdiDdDDIGetScanLine, 1)
    SVC_(GdiDdDDIGetSharedPrimaryHandle, 1)
    SVC_(GdiDdDDIInvalidateActiveVidPn, 1)
    SVC_(GdiDdDDILock, 1)
    SVC_(GdiDdDDIOpenAdapterFromDeviceName, 1)
    SVC_(GdiDdDDIOpenAdapterFromGdiDisplayName, 1)
    SVC_(GdiDdDDIOpenAdapterFromHdc, 1)
    SVC_(GdiDdDDIOpenResource, 1)
    SVC_(GdiDdDDIPollDisplayChildren, 1)
    SVC_(GdiDdDDIPresent, 1)
    SVC_(GdiDdDDIQueryAdapterInfo, 1)
    SVC_(GdiDdDDIQueryAllocationResidency, 1)
    SVC_(GdiDdDDIQueryResourceInfo, 1)
    SVC_(GdiDdDDIQueryStatistics, 1)
    SVC_(GdiDdDDIReleaseProcessVidPnSourceOwners, 1)
    SVC_(GdiDdDDIRender, 1)
    SVC_(GdiDdDDISetAllocationPriority, 1)
    SVC_(GdiDdDDISetContextSchedulingPriority, 1)
    SVC_(GdiDdDDISetDisplayMode, 1)
    SVC_(GdiDdDDISetDisplayPrivateDriverFormat, 1)
    SVC_(GdiDdDDISetGammaRamp, 1)
    SVC_(GdiDdDDISetProcessSchedulingPriorityClass, 2)
    SVC_(GdiDdDDISetQueuedLimit, 1)
    SVC_(GdiDdDDISetVidPnSourceOwner, 1)
    SVC_(GdiDdDDISharedPrimaryLockNotification, 1)
    SVC_(GdiDdDDISharedPrimaryUnLockNotification, 1)
    SVC_(GdiDdDDISignalSynchronizationObject, 1)
    SVC_(GdiDdDDIWaitForSynchronizationObject, 1)
