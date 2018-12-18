#pragma once
/* Hebrew text is in visual order */

static MUI_ENTRY heILLanguagePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "��� �����",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  .������ ����� ���� ���� �� ��� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   .ENTER ��� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  .������ ������ ����� ����� ��� ���� ��� ���",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILWelcomePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "ReactOS ������ ����� ������",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        6,
        11,
        "ReactOS ������ ����� �� ����� ������ �� ��� ����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        ".������ �� ���� ���� �� ����� ������",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  .ReactOS �� ����� �� ������ ��� ENTER ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
     // "\x07  Press R to repair a ReactOS installation using the Recovery Console.",
        "\x07  .ReactOS ����� ���� ��� R ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  .ReactOS �� ������ ���� ����� ��� L ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  .ReactOS �� ������ ���� ���� ��� F3 ���",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        23,
        ":���� ���� ���� ,ReactOS ���� ���� �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        24,
        "http://www.reactos.org",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        0,
        0,
        "����� ����� = F3  ����� = L  ����� ����� = R  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILIntroPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "ReactOS ���� ���",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        6,
        11,
        "������ ������� �� ��� ������ ,���� ���� ����� ReactOS",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "���� �� ������ ������ ����� .����� ����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        ".��� ��� ����� ���� ����� ���� ��� ������� ����� ������",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "���� ����� ������ �� ��� ����� �� ����� �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        ".����� ����� �� ReactOS �� ����� ��� ��",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  .ReactOS ����� �� ������ ��� ENTER ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  .ReactOS �� ������ ���� ���� ��� F3 ���",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILLicensePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        6,
        ":�����",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        8,
        "The ReactOS System is licensed under the terms of the",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        9,
        "GNU GPL with parts containing code from other compatible",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "licenses such as the X11 or BSD and GNU LGPL licenses.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "All software that is part of the ReactOS system is",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        12,
        "therefore released under the GNU GPL as well as maintaining",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "the original license.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "This software comes with NO WARRANTY or restrictions on usage",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        16,
        "save applicable local and international law. The licensing of",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "ReactOS only covers distribution to third parties.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        18,
        "If for some reason you did not receive a copy of the",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "GNU General Public License with ReactOS please visit",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        20,
        "http://www.gnu.org/licenses/licenses.html",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        22,
        ":������",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        24,
        "This is free software; see the source for copying conditions.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        25,
        "There is NO warranty; not even for MERCHANTABILITY or",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        26,
        "FITNESS FOR A PARTICULAR PURPOSE",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "���� �� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILDevicePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        ".�������� ������� ������ �� ���� ���� ������",
        TEXT_STYLE_NORMAL
    },
    {
        24,
        11,
        ":����",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        12,
        ":�����",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        13,
        ":�����",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        14,
        ":����� �����",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        16,
        ":�����",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        25,
        16, "������� ������ �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        19,
        "���� ����� �� ������ ������� ������ ���� ������ �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        20,
        ".���� ����� ����� ��� ENTER ��� �� .���� ����� ���",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        21,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        23,
        "\"������� ������ �����\"� ��� ,������ ������� ��� ���",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        24,
        ".ENTER ����",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILRepairPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        ".����� ����� ���� ����� ReactOS �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        ".����� ����� ����� �� ������� �� �� ������ �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        ".������� ����� ���� ������ ������",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  .������ �� ����� ��� U ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  .������ ���� �� ����� ��� R ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  .����� ����� ����� ��� ESC ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  .����� �� ���� ������ ��� ENTER ���",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "���� ����� = ENTER  ����� = R  ����� = U  ���� ���� = ESC",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILUpgradePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "ReactOS ������� ��� �� ����� ����� ReactOS �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "������ ����� ,����� �������� ��� �� �� ,���� �������",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        ".����� ����� �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        ".������ ������ ���� ������ �����",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        15,
        "\x07  .����� ����� ��� ���� �� ����� �� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  .������ ������ ����� �� ����� ��� U ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  .���� ����� ����� �� ������ ��� ESC ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  .ReactOS �� ������ ���� ���� ��� F3 ���",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ����� �� = ESC  ����� = ESC",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILComputerPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        ".������ ����� ��� �� ����� ���� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  .����� ����� ��� �� ����� ��� ���� �� ����� �� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   .ENTER ��� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  .����� ��� �� ����� ���� ����� ����� ����� ��� ESC �� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ����� = ESC  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILFlushPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "��� ����� �� ���� ����� ��� ����� ����� ������",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "���� ��� ���� ���� ��",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "������� ����� ���� ����� ����� ,�����",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "������ �� ����",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILQuitPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "��� ����� ������ �� ReactOS",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        " :A ����� �������� �� ������ ��",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        ".�������� ���������� �� ���",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        11,
        ".����� �� ���� ������ ��� ENTER ���",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "...������ ��",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILDisplayPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        ".������ ������ ��� �� ����� ������",
        TEXT_STYLE_NORMAL
    },
    {   8,
        10,
         "\x07  .����� ������ ��� �� ����� ��� ���� �� ����� �� ���",
         TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   .ENTER ��� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  .������ ��� �� ����� ���� ����� ��� ESC ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ����� = ESC  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILSuccessPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        ".������ ������ ReactOS �� �������� �������",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        " :A ����� �������� �� ������ ��",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        ".�������� ���������� �� ���",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        11,
        ".����� �� ���� ������ ��� ENTER ���",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "���� ����� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILBootPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "����� ����� �� ������ ���� �� ������ ����� ���� ������",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "������",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        ".ENTER ���� :A ����� ������ ������� ���� �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "",
        TEXT_STYLE_NORMAL,
    },
    {
        0,
        0,
        "����� ����� = F3  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }

};

static MUI_ENTRY heILSelectPartitionEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "����� �� ���� ���� ������ ������ ���� ������",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        ".����� ������ ����",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "\x07  .����� ����� ��� ���� �� ����� �� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  .������ ������ �� ReactOS �� ������ ��� ENTER ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  .����� ����� ����� ��� P ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  .������ ����� ����� ��� E ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  .����� ����� ����� ��� L ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  .����� ����� ����� ��� D ���",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "...������ ��",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILConfirmDeleteSystemPartitionEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        ".����� ����� ����� ����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        ",����� ����� ������� ,����� ������� ����� ������ ����� ������",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        11,
        ")ReactOS ���( ����� ������ ������ ������",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        ".������ ���� ��� �� �������� ����� ������ ��",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "���� ������ ���� ���� ��� �� �� ����� ����� ���",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        ".���� ����� ���� ���� �� ,������ ��",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "����� ������ ����� �� ���� ����� ,������ ����� ���",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        17,
        ".ReactOS ����� ����� ��",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        20,
        "\x07  ������ ����� ����� .������ ����� �� ����� ��� ENTER ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "   .������ ���� ����� �����",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        24,
        "\x07  .����� �� ������ ,����� ����� ����� ��� ESC ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        25,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� = ESC  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILFormatPartitionEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "����� �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        ".������ ��� ENTER ��� .������ �� ����� ����� ������",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        TEXT_STYLE_NORMAL
    }
};

static MUI_ENTRY heILInstallDirectoryEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        ".������ ������ �� ReactOS �� ����� ������",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        ":ReactOS �� ������ ������ �� ������ ���",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "����� ��� BACKSPACE ��� ,������ ������� �� ����� ���",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        ".ReactOS �� ������ ������ �� ������� �� ����� ��� �����",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILFileCopyEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        0,
        12,
        "����� ������ ReactOS ������ ���� ������ ��",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER
    },
    {
        0,
        13,
        ".����� ������ �������",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER
    },
    {
        0,
        14,
        ".���� ���� ����� ����� �� �����",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER
    },
    {
        50,
        0,
        "\xB3 ...������ ��    ",
        TEXT_TYPE_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILBootLoaderEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "������ ���� �� ��� ������ ������ �����",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        12,
        ".(VBR-� MBR) ����� ���� �� ����� ���� ����",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        ".(���� VBR) ����� ���� �� ����� ���� ����",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        ".������� �� ����� ���� ����",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        ".������ ���� ����� �� �����",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILKeyboardSettingsEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        ".������� ������ ��� ����� ������",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  .����� ������ ��� �� ����� ��� ���� �� ����� �� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   .ENTER ��� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  .������ ��� �� ����� ���� ����� ����� ����� ��� ESC �� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ����� = ESC  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILLayoutSettingsEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        ".���� ����� ������� ������ ����� �� ����� ��",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  .������ ������ �� ����� ��� ���� �� ����� �� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "    .ENTER ��� ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  .������ ����� �� ����� ���� ����� ����� ����� ��� ESC ���",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ����� = ESC  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY heILPrepareCopyEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        ".ReactOS ���� ������ ����� �� ����� ������ ����� ",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "...����� ����� ����� ����",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY heILSelectFSEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        17,
        ".���� ������� ����� ����� ���",
        0
    },
    {
        8,
        19,
        "\x07  .����� ����� ����� ��� ���� �� ����� �� ���",
        0
    },
    {
        8,
        21,
        "\x07  .������ �� ����� ��� ENTER ���",
        0
    },
    {
        8,
        23,
        "\x07  .���� ����� ����� ��� ESC ���",
        0
    },
    {
        0,
        0,
        "����� ����� = F3  ����� = ESC  ���� = ENTER",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },

    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILDeletePartitionEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "������ �� ����� ����",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        18,
        "\x07  .������ �� ����� ��� D ���",
        TEXT_STYLE_NORMAL
    },
    {
        11,
        19,
        "!���� ������ ����� �� :�����",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  .���� ��� ESC ���",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "����� ����� = F3  ����� = ESC  ����� ��� = D",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY heILRegistryEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " ����� ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        " .������ ����� �� ����� ������ �����",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "...������ ������ ����",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

MUI_ERROR heILErrorEntries[] =
{
    {
        // NOT_AN_ERROR
        "�����\n"
    },
    {
        // ERROR_NOT_INSTALLED
        ".����� �� ��� ����� ������ �� ReactOS\n"
        "��� ������ �� ������ ����� ,��� ������� ��� ��\n"
        ".ReactOS �� ������ ���\n"
        "\n"
        "  \x07  .������� ������ ��� ENTER ���\n"
        "  \x07  .������� ���� ��� F3 ���",
        "����� ����� = F3  ���� = ENTER"
    },
    {
        // ERROR_NO_HDD
        ".���� ���� ���� �� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_NO_SOURCE_DRIVE
        ".��� ����� ���� �� ���� �� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_LOAD_TXTSETUPSIF
        ".TXTSETUP.SIF ���� �� ���� �� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_CORRUPT_TXTSETUPSIF
        ".���� TXTSETUP.SIF ����� �� ���� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_SIGNATURE_TXTSETUPSIF,
        ".TXTSETUP.SIF-� ����� ����� ���� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_DRIVE_INFORMATION
        ".������ �� ������� ���� �� ����� ���� �� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_WRITE_BOOT,
        ".������ ����� �� %S �� ������ ��� �� ������� ����� ������ �����",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_LOAD_COMPUTER,
        ".������� ���� ����� ������ ����� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_LOAD_DISPLAY,
        ".������ ������ ���� ����� ������ ����� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_LOAD_KEYBOARD,
        ".������� ���� ����� ������ ����� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_LOAD_KBLAYOUT,
        ".������ ������ ����� ������ ����� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_WARN_PARTITION,
        "��� ���� ���� ����� ���� ������ �����\n"
        "!�� ������� ����� ����� ��� ������ ���� ���\n"
        "\n"
        ".������� ���� �� ������ ����� ����� ����� �� �����\n"
        "\n"
        "  \x07  .������ ������ F3 ���\n"
        "  \x07  .������ ��� ENTER ���",
        "����� ����� = F3  ���� = ENTER"
    },
    {
        // ERROR_NEW_PARTITION,
        "!����� ����� ���� ����� ����� ���� ��\n"
        "\n"
        ".������ ��� ��� �� ��� *  ",
        NULL
    },
    {
        // ERROR_DELETE_SPACE,
        "!����� ��� ���� ��� ����� ���� ��\n"
        "\n"
        ".������ ��� ��� �� ��� *  ",
        NULL
    },
    {
        // ERROR_INSTALL_BOOTCODE,
        ".������ ����� �� %S ���� ����� ��� ������ ����� ������ �����",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_NO_FLOPPY,
        ".:A ����� ������� ���",
        "���� = ENTER"
    },
    {
        // ERROR_UPDATE_KBSETTINGS,
        ".������ ����� ������ �� ������ ����� ������ �����",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_UPDATE_DISPLAY_SETTINGS,
        ".������ ���� ������ �� ������ ����� ������ �����",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_IMPORT_HIVE,
        ".����� ����� ���� ������ ����� ������ �����",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_FIND_REGISTRY
        "����� ������ ����� ������ �� ���� ���� ������.",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_CREATE_HIVE,
        ".������ ������ ������ ����� ������ �����",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_INITIALIZE_REGISTRY,
        ".������ ������ ����� ������ �����",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_INVALID_CABINET_INF,
        ".inf ���� ��� Cabinet �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_CABINET_MISSING,
        ".���� �� Cabinet ����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_CABINET_SCRIPT,
        "����� Cabinet ��� ����� �����.\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_COPY_QUEUE,
        ".����� ����� ��� ������ ����� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_CREATE_DIR,
        ".������ ������ �� ����� ���� �� ������ �����",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_TXTSETUP_SECTION,
        ".TXTSETUP.SIF� '%S' ��� �� ����� ����� ������ �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_CABINET_SECTION,
        "'%S' ��� �� ����� ����� ������ �����\n"
        ".Cabinet �����\n",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_CREATE_INSTALL_DIR
        ".������ ������ �� �� ����� ���� �� ������ �����",
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_WRITE_PTABLE,
        ".������� ���� ������ ����� ������ �����\n"
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_ADDING_CODEPAGE,
        ".������ codepage ������ ����� ������ �����\n"
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_UPDATE_LOCALESETTINGS,
        ".������ ���� �� ����� ���� �� ������ �����n"
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_ADDING_KBLAYOUTS,
        ".������ ����� ������ ������ ����� ������ �����\n"
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_UPDATE_GEOID,
        ".geo id � �� ����� ���� �� ������ �����\n"
        "����� �� ���� ���� = ENTER"
    },
    {
        // ERROR_DIRECTORY_NAME,
        ".���� �� ������ ��\n"
        "\n"
        ".������ ��� ��� �� ��� *  "
    },
    {
        // ERROR_INSUFFICIENT_PARTITION_SIZE,
        ".ReactOS �� ������ ��� ����� ����� �� ������ ������\n"
        ".�\"� %lu �� ����� ����� ����� ����� ������ �����\n"
        "\n"
        ".������ ��� ��� �� ��� *  ",
        NULL
    },
    {
        // ERROR_PARTITION_TABLE_FULL,
        "�� ���� ����� ����� ���� �� ����� ������ ����\n"
        ".������ ������� ���� ��� ���� ����� �� ������� ���� ��\n"
        "\n"
        ".������ ��� ��� �� ��� *  "
    },
    {
        // ERROR_ONLY_ONE_EXTENDED,
        ".���� ���� ��� ��� ������ ������ ���� ����� ���� ��\n"
        "\n"
        ".������ ��� ��� �� ��� *  "
    },
    {
        // ERROR_FORMATTING_PARTITION,
        ":������ �� ����� ���� �� ������ �����\n"
        " %S\n"
        "\n"
        "����� �� ���� ���� = ENTER"
    },
    {
        NULL,
        NULL
    }
};

MUI_PAGE heILPages[] =
{
    {
        LANGUAGE_PAGE,
        heILLanguagePageEntries
    },
    {
        WELCOME_PAGE,
        heILWelcomePageEntries
    },
    {
        INSTALL_INTRO_PAGE,
        heILIntroPageEntries
    },
    {
        LICENSE_PAGE,
        heILLicensePageEntries
    },
    {
        DEVICE_SETTINGS_PAGE,
        heILDevicePageEntries
    },
    {
        REPAIR_INTRO_PAGE,
        heILRepairPageEntries
    },
    {
        UPGRADE_REPAIR_PAGE,
        heILUpgradePageEntries
    },
    {
        COMPUTER_SETTINGS_PAGE,
        heILComputerPageEntries
    },
    {
        DISPLAY_SETTINGS_PAGE,
        heILDisplayPageEntries
    },
    {
        FLUSH_PAGE,
        heILFlushPageEntries
    },
    {
        SELECT_PARTITION_PAGE,
        heILSelectPartitionEntries
    },
    {
        CONFIRM_DELETE_SYSTEM_PARTITION_PAGE,
        heILConfirmDeleteSystemPartitionEntries
    },
    {
        SELECT_FILE_SYSTEM_PAGE,
        heILSelectFSEntries
    },
    {
        FORMAT_PARTITION_PAGE,
        heILFormatPartitionEntries
    },
    {
        DELETE_PARTITION_PAGE,
        heILDeletePartitionEntries
    },
    {
        INSTALL_DIRECTORY_PAGE,
        heILInstallDirectoryEntries
    },
    {
        PREPARE_COPY_PAGE,
        heILPrepareCopyEntries
    },
    {
        FILE_COPY_PAGE,
        heILFileCopyEntries
    },
    {
        KEYBOARD_SETTINGS_PAGE,
        heILKeyboardSettingsEntries
    },
    {
        BOOT_LOADER_PAGE,
        heILBootLoaderEntries
    },
    {
        LAYOUT_SETTINGS_PAGE,
        heILLayoutSettingsEntries
    },
    {
        QUIT_PAGE,
        heILQuitPageEntries
    },
    {
        SUCCESS_PAGE,
        heILSuccessPageEntries
    },
    {
        BOOT_LOADER_FLOPPY_PAGE,
        heILBootPageEntries
    },
    {
        REGISTRY_PAGE,
        heILRegistryEntries
    },
    {
        -1,
        NULL
    }
};

MUI_STRING heILStrings[] =
{
    {STRING_PLEASEWAIT,
     "   ...������ ��"},
    {STRING_INSTALLCREATEPARTITION,
     "   ����� ����� = F3  ������ ��� = E  ����� ��� = P  ���� = ENTER"},
    {STRING_INSTALLCREATELOGICAL,
     "   ����� ����� = F3  ����� ����� ��� = L  ���� = ENTER"},
    {STRING_INSTALLDELETEPARTITION,
     "   ����� ����� = F3  ����� ��� = D  ���� = ENTER"},
    {STRING_DELETEPARTITION,
     "   ����� ����� = F3  ����� ��� = D"},
    {STRING_PARTITIONSIZE,
     ":���� ����� �� ����"},
    {STRING_CHOOSENEWPARTITION,
     "�� ������ ����� ����� ����"},
    {STRING_CHOOSE_NEW_EXTENDED_PARTITION,
     "�� ������ ����� ����� ����"},
    {STRING_CHOOSE_NEW_LOGICAL_PARTITION,
     "�� ����� ����� ����� ����"},
    {STRING_HDDSIZE,
    ".����-���� ����� ������ �� ����� �� ���� �����"},
    {STRING_CREATEPARTITION,
     "   ����� ����� = F3  ����� = ESC  ����� ��� = ENTER"},
    {STRING_PARTFORMAT,
    ".����� ������ ���� ������"},
    {STRING_NONFORMATTEDPART,
    ".������� ��/���� ����� �� ReactOS �� ������ ����"},
    {STRING_NONFORMATTEDSYSTEMPART,
    ".������� �� ����� ������ �����"},
    {STRING_NONFORMATTEDOTHERPART,
    ".������� �� ����� ����� ������"},
    {STRING_INSTALLONPART,
    "����� �� ReactOS �� ������ ������ �����"},
    {STRING_CHECKINGPART,
    ".������ ������ �� ����� ����� ������ �����"},
    {STRING_CONTINUE,
    "���� = ENTER"},
    {STRING_QUITCONTINUE,
    "���� = ENTER  ����� ����� = F3"},
    {STRING_REBOOTCOMPUTER,
    "���� ����� = ENTER"},
    {STRING_DELETING,
     "   ���� ����: %S"},
    {STRING_MOVING,
     "   ���� �����: %S �: %S"},
    {STRING_RENAMING,
     "   ���� �� ����: %S �: %S"},
    {STRING_COPYING,
     "   ���� �����: %S"},
    {STRING_SETUPCOPYINGFILES,
     "...����� ������ ������ �����"},
    {STRING_REGHIVEUPDATE,
    "   ...������ ������ �� �����"},
    {STRING_IMPORTFILE,
    "   ����� %S..."},
    {STRING_DISPLAYSETTINGSUPDATE,
    "   ...������ �� ����� ������ �����"},
    {STRING_LOCALESETTINGSUPDATE,
    "   ...���� ������ �����"},
    {STRING_KEYBOARDSETTINGSUPDATE,
    "   ...������ ����� ������ �� �����"},
    {STRING_CODEPAGEINFOUPDATE,
    "   ...������ codepage ���� �����"},
    {STRING_DONE,
    "   ...�����"},
    {STRING_REBOOTCOMPUTER2,
    "   ����� �� ���� ���� = ENTER"},
    {STRING_REBOOTPROGRESSBAR,
    " ...����� %li ���� ���� ����� ����� "},
    {STRING_CONSOLEFAIL1,
    "����� �� ����� ���� ��\r\n\r\n"},
    {STRING_CONSOLEFAIL2,
    "USB ������ ����� ��� �� �� ����� ��� �����\r\n"},
    {STRING_CONSOLEFAIL3,
    "��� ����� ������ �� ����� USB ������\r\n"},
    {STRING_FORMATTINGDISK,
    "����� �� ������ ������ �����"},
    {STRING_CHECKINGDISK,
    "����� �� ����� ������ �����"},
    {STRING_FORMATDISK1,
    " (���� �����) %S ����� ����� �� ����� ����� "},
    {STRING_FORMATDISK2,
    " %S ����� ����� �� ����� ����� "},
    {STRING_KEEPFORMAT,
    " (����� ���( ������ ����� ����� ����� "},
    {STRING_HDINFOPARTCREATE_1,
    "%I64u %s  Harddisk %lu  (Port=%hu, Bus=%hu, Id=%hu) on %wZ [%s]."},
    {STRING_HDINFOPARTCREATE_2,
    "%I64u %s  Harddisk %lu  (Port=%hu, Bus=%hu, Id=%hu) [%s]."},
    {STRING_HDDINFOUNK2,
    "   %c%c  Type 0x%02X    %I64u %s"},
    {STRING_HDINFOPARTDELETE_1,
    "on %I64u %s  Harddisk %lu  (Port=%hu, Bus=%hu, Id=%hu) on %wZ [%s]."},
    {STRING_HDINFOPARTDELETE_2,
    "on %I64u %s  Harddisk %lu  (Port=%hu, Bus=%hu, Id=%hu) [%s]."},
    {STRING_HDINFOPARTZEROED_1,
    "Harddisk %lu (%I64u %s), Port=%hu, Bus=%hu, Id=%hu (%wZ) [%s]."},
    // {STRING_HDINFOPARTZEROED_2,
    // "Harddisk %lu (%I64u %s), Port=%hu, Bus=%hu, Id=%hu [%s]."},
    {STRING_HDDINFOUNK4,
    "%c%c  Type 0x%02X    %I64u %s"},
    {STRING_HDINFOPARTEXISTS_1,
    "on Harddisk %lu (%I64u %s), Port=%hu, Bus=%hu, Id=%hu (%wZ) [%s]."},
    // {STRING_HDINFOPARTEXISTS_2,
    // "on Harddisk %lu (%I64u %s), Port=%hu, Bus=%hu, Id=%hu [%s]."},
    {STRING_HDDINFOUNK5,
    "%c%c %c %sType %-3u%s                      %6lu %s"},
    {STRING_HDINFOPARTSELECT_1,
    "%6lu %s  Harddisk %lu  (Port=%hu, Bus=%hu, Id=%hu) on %wZ [%s]"},
    {STRING_HDINFOPARTSELECT_2,
    "%6lu %s  Harddisk %lu  (Port=%hu, Bus=%hu, Id=%hu) [%s]"},
    {STRING_NEWPARTITION,
    "�� ���� ����� ���� ������ �����"},
    {STRING_UNPSPACE,
    "    %sUnpartitioned space%s            %6lu %s"},
    {STRING_MAXSIZE,
    "�\"� (���. ul% �\"�)"},
    {STRING_EXTENDED_PARTITION,
    "������ �����"},
    {STRING_UNFORMATTED,
    ")������ ��( ���"},
    {STRING_FORMATUNUSED,
    "������ ��"},
    {STRING_FORMATUNKNOWN,
    "���� ��"},
    {STRING_KB,
    "�\"�"},
    {STRING_MB,
    "�\"�"},
    {STRING_GB,
    "�\"�"},
    {STRING_ADDKBLAYOUTS,
    "...����� ������ �����"},
    {0, 0}
};
