# Nom de l'installateur
OutFile "Nebula_Striker_installer.exe"

# Le répertoire d'installation par défaut
InstallDir "$PROGRAMFILES\Nebula Striker"

# Les sections sont des parties essentielles de l'installateur

Section "Nebula Striker" SecMain

    # Définir le répertoire d'installation
    SetOutPath $INSTDIR

    # Copier les fichiers de votre application
    # Remplacez 'MonExecutable.exe' et 'MaBibliotheque.dll' par les fichiers réels de votre application
    File "Nebula Striker.exe"
    File "engine_lib.dll"

    # Créer un raccourci dans le menu démarrer
    CreateDirectory "$SMPROGRAMS\Nebula Striker"
    CreateShortCut "$SMPROGRAMS\Nebula Stiker\Nebula Striker.lnk" "$INSTDIR\Nebula Striker.exe"

SectionEnd

# Section de désinstallation

Section "Uninstall"

    # Supprimer les fichiers installés
    Delete "$INSTDIR\Nebula Striker.exe"
    Delete "$INSTDIR\engine_lib.dll"

    # Supprimer le répertoire d'installation si vide
    RMDir "$INSTDIR"

    # Supprimer le raccourci dans le menu démarrer
    Delete "$SMPROGRAMS\Nebula Striker\Nebula Striker.lnk"
    RMDir "$SMPROGRAMS\Nebula Striker"

SectionEnd