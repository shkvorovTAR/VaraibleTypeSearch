# VaraibleTypeSearch
https://github.com/Anaga/TARvg17/tree/master/Conteiners/Conteiners/HomeWork
TARgv17 Homework: Get Varaible type and number from ini file.

You need to write a console application, that read and search varaible from input ini text file.

Application shall search varaible by in name, and dispay type and number of this varaible from ini file. If no var with this name - notify user.

Please use T_variable struct

typedef struct {
    QString varName;
    QString varType;
    int varId;
} T_variable;

If we use dl_gsw.ini, and user start applicatin:

    Please enter name to search, or 0 to exit:
    PHASE_SM0
    Varaible 'PHASE_SM0' have type 'U8' and number '42'

    Please enter name to search, or 0 to exit:
    TARGET_GAUGE2
    Varaible 'TARGET_GAUGE2' have type 'U16' and number '58'

    Please enter name to search, or 0 to exit:
    TARGET_GAUGE4
    Can't find Varaible 'TARGET_GAUGE4' in file 'dl_gsw.ini'

    Please enter name to search, or 0 to exit:
    MAX_EXEC_LOGIC_PT
    Varaible 'MAX_EXEC_LOGIC_PT' have type 'U32' and number '86'

    Please enter name to search, or 0 to exit:
    0
    Good bay!

В задании - Get Varaible нужно прочитать ини файл, и предложить пользователю поиск переменной по ее имени. Если переменная с таким именем есть в файле - то вывести ее тип и номер. 
