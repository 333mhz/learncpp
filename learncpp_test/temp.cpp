            
            switch (mapStrGrpDat->m_byAttr):
            case NHTM_CMD_CLASS_SINGLE:			// 对于0x45.GRP1可以有多种属性对应，属性0=直接数据写入，属性255=非组标识命令，属性254=带有组标识的命令。
			{															// 属性255=非组标识命令
				strGrpVal.Format(_T("%s"), strP3);
				strGrpVal.Trim();
				if(!strGrpVal.IsEmpty())					// 如果比较项不是空，则比较。
				{
					b = mapStrGrpDat->m_mapValPos.Lookup(strP3, strGrpPos);
					if(!b)
						continue;
				}
				// 命令比较
				int iCmdNumber;
				CString strCmd;

				iCmdNumber = mapStrGrpDat->m_strArrayCmds.GetSize();
				strCmd.Format(_T("%s"), strP4);
				strCmd.Trim();
				if(strCmd.IsEmpty())
				{
					if(strGrpVal.IsEmpty())
						continue;								// 如果比较和命令都是空，则不符合条件，继续下面。
					else
					{											// 如果命令是空，比较不是空，且有符合项，但无命令比较项存在时，因此只有比较项有效。
						if(iCmdNumber == 0)
						{
							if(mapStrGrpDat->m_strName.Compare(_T("OK"))==0)			// 如果已经是NG了，则表示其中至少一个已经失败，则整体失败。
								mapStrGrpDat->m_strName.Format(_T("%s"), strP7);
							mapStrGrpDat->bValid = NHTM_GROUP_USED;

							break;
						}
					}
				}

				for(int i=0; i<iCmdNumber; i++)
				{
					if(mapStrGrpDat->m_strArrayCmds[i].Compare(strCmd) == 0)		// 找到
					{
						if(mapStrGrpDat->m_strName.Compare(_T("OK"))==0)			// 如果已经是NG了，则表示其中至少一个已经失败，则整体失败。
							mapStrGrpDat->m_strName.Format(_T("%s"), strP7);
						mapStrGrpDat->bValid = NHTM_GROUP_USED;

						break;
					}
				}
			}
			else if(mapStrGrpDat->m_byAttr==NHTM_CMD_CLASS_GROUP)			// 属性254=带有组标识的命令
			{
				strGrpVal.Format(_T("%s"), strP8);
				strGrpVal.Trim();
				if(strGrpVal.IsEmpty())					// 如果比较项不是空，则比较。
					continue;
				b = mapStrGrpDat->m_mapValPos.Lookup(strP8, strGrpPos);	// strP8 = 命令分组标识符（非单品测试命令）
				if(!b)
					continue;
				if(mapStrGrpDat->m_strName.Compare(_T("OK"))==0)			// 如果已经是NG了，则表示其中至少一个已经失败，则整体失败。
					mapStrGrpDat->m_strName.Format(_T("%s"), strP7);
				mapStrGrpDat->bValid = NHTM_GROUP_USED;

				// 追加Reject计数
				CString strStrPart, strIntPart;
				strStrPart = strIntPart = _T("");
				b = toolString2StrInt(strGrpPos, strStrPart, strIntPart);
				if(b && (strStrPart != _T("")) && (strIntPart != _T("")) && (_wtoi(strIntPart) != 0))
				{
					CReportDataItem *rptDataItem = new CReportDataItem;
					rptDataItem->m_byAttr = NHTM_IN_DATA_STRING;		// 属性0
					rptDataItem->iLine = 0;
					rptDataItem->m_strPos = strGrpPos;					// 直接写入位置
					rptDataItem->m_strValue.Format(_T("%s"), strP16);	// 直接写入reject check number(P2)
					rptDataItem->m_strP2.Format(_T("%s"), strP2);		// 保留项目类别名，作为区分【基本信息】中是否有重复记录用（20170721）
					rptDataItem->m_strP3.Format(_T("%s"), strP3);		// 保留项目类别标识名，作为区分【基本信息】中是否有重复记录用（20170721）
					rptDataItem->m_strP14.Format(_T("%s"), strP14);		// 保留项目Barcode(P2)
					str.Format(_T("%d"), m_RP.m_iReportItemNumber++);
					m_RP.m_mapRptItems.SetAt(str, rptDataItem);
				}

				break;
			}
			// P3 Start
			else if(mapStrGrpDat->m_byAttr==NHTM_CMD_CLASS_SINGLE_EX)	// 属性252=非组标识命令，单品测试命令的扩展命令
			{
				strGrpVal.Format(_T("%s"), strP3);
				strGrpVal.Trim();
				if(!strGrpVal.IsEmpty())					// 如果比较项不是空，则比较。
				{
					b = mapStrGrpDat->m_mapValPos.Lookup(strP3, strGrpPos);	// strP3 = compare item
					if(!b)
						continue;
				}

				// 命令比较
				int iCmdNumber;
				CString strCmd;

				iCmdNumber = mapStrGrpDat->m_strArrayCmds.GetSize();
				strCmd.Format(_T("%s"), strP4);
				strCmd.Trim();
				if(strCmd.IsEmpty())
				{
					if(strGrpVal.IsEmpty())
						continue;								// 如果比较和命令都是空，则不符合条件，继续下面。
					else
					{											// 如果命令是空，比较不是空，且有符合项，但无命令比较项存在时，因此只有比较项有效。
						if(iCmdNumber == 0)
						{
							if(mapStrGrpDat->m_strName.Compare(_T("OK"))==0)			// 如果已经是NG了，则表示其中至少一个已经失败，则整体失败。
								mapStrGrpDat->m_strName.Format(_T("%s"), strP7);
							mapStrGrpDat->bValid = NHTM_GROUP_USED;

							CReportDataItem *rptDataItem = new CReportDataItem;
							rptDataItem->m_byAttr = 0;							// 属性0
							rptDataItem->iLine = 0;
							rptDataItem->m_strPos = strGrpPos;					// 直接写入位置
							rptDataItem->m_strValue.Format(_T("%s"), strP6);	// 直接写入数值内容
							rptDataItem->m_strP2.Format(_T("%s"), strP2);		// 保留项目类别名，作为区分【基本信息】中是否有重复记录用（20170721）
							rptDataItem->m_strP3.Format(_T("%s"), strP3);		// 保留项目类别标识名，作为区分【基本信息】中是否有重复记录用（20170721）
							rptDataItem->m_strP14.Format(_T("%s"), strP14);		// 保留项目Barcode(P2)
							str.Format(_T("%d"), m_RP.m_iReportItemNumber++);
							m_RP.m_mapRptItems.SetAt(str, rptDataItem);

							break;
						}
					}
				}

				for(int i=0; i<iCmdNumber; i++)
				{
					if(mapStrGrpDat->m_strArrayCmds[i].Compare(strCmd) == 0)		// 找到
					{
						if(mapStrGrpDat->m_strName.Compare(_T("OK"))==0)			// 如果已经是NG了，则表示其中至少一个已经失败，则整体失败。
							mapStrGrpDat->m_strName.Format(_T("%s"), strP7);
						mapStrGrpDat->bValid = NHTM_GROUP_USED;

						CReportDataItem *rptDataItem = new CReportDataItem;
						rptDataItem->m_byAttr = 0;							// 属性0
						rptDataItem->iLine = 0;
						rptDataItem->m_strPos = strGrpPos;					// 直接写入位置
						rptDataItem->m_strValue.Format(_T("%s"), strP6);	// 直接写入数值内容
						rptDataItem->m_strP2.Format(_T("%s"), strP2);		// 保留项目类别名，作为区分【基本信息】中是否有重复记录用（20170721）
						rptDataItem->m_strP3.Format(_T("%s"), strP3);		// 保留项目类别标识名，作为区分【基本信息】中是否有重复记录用（20170721）
						rptDataItem->m_strP14.Format(_T("%s"), strP14);		// 保留项目Barcode(P2)
						str.Format(_T("%d"), m_RP.m_iReportItemNumber++);
						m_RP.m_mapRptItems.SetAt(str, rptDataItem);

						break;
					}
				}
			}// P3 End
			else if (mapStrGrpDat->m_byAttr == NHTM_CMD_CLASS_GROUP_EX)
			{

			}
			else
			{														// 属性0=直接数据写入
				b = mapStrGrpDat->m_mapValPos.Lookup(strP3, strGrpPos);
				if(b)
				{
					CReportDataItem *rptDataItem = new CReportDataItem;
					rptDataItem->m_byAttr = mapStrGrpDat->m_byAttr;		// 属性0
					rptDataItem->iLine = 0;
					rptDataItem->m_strPos = strGrpPos;					// 直接写入位置
					rptDataItem->m_strValue.Format(_T("%s"), strP6);	// 直接写入数值内容
					rptDataItem->m_strP2.Format(_T("%s"), strP2);		// 保留项目类别名，作为区分【基本信息】中是否有重复记录用（20170721）
					rptDataItem->m_strP3.Format(_T("%s"), strP3);		// 保留项目类别标识名，作为区分【基本信息】中是否有重复记录用（20170721）
					rptDataItem->m_strP14.Format(_T("%s"), strP14);		// 保留项目Barcode(P2)
					str.Format(_T("%d"), m_RP.m_iReportItemNumber++);
					m_RP.m_mapRptItems.SetAt(str, rptDataItem);

					if(mapStrGrpDat->m_strName.Compare(_T("OK"))==0)			// 如果已经是NG了，则表示其中至少一个已经失败，则整体失败。
						mapStrGrpDat->m_strName.Format(_T("%s"), strP7);
					mapStrGrpDat->bValid = NHTM_GROUP_USED;

					bRst = true;
					break;
				}
			}