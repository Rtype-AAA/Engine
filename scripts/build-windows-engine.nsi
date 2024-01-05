# Nom de l'installateur
OutFile "QuantumVortex_Engine_installer.exe"

# Le répertoire d'installation par défaut
InstallDir "$PROGRAMFILES\QuantumVortex Engine"

# Les sections sont des parties essentielles de l'installateur

Section "QuantumVortex Engine" SecMain

    # Définir le répertoire d'installation
    SetOutPath $INSTDIR

    # Copier les fichiers de votre application
    # Remplacez 'MonExecutable.exe' et 'MaBibliotheque.dll' par les fichiers réels de votre application
    File "QuantumVortex Engine.exe"
    File "engine_lib.dll"

    # Créer un raccourci dans le menu démarrer
    CreateDirectory "$SMPROGRAMS\QuantumVortex Engine"
    CreateShortCut "$SMPROGRAMS\Nebula Stiker\QuantumVortex Engine.lnk" "$INSTDIR\QuantumVortex Engine.exe"

SectionEnd

# Section de désinstallation

Section "Uninstall"

    # Supprimer les fichiers installés
    Delete "$INSTDIR\QuantumVortex Engine.exe"
    Delete "$INSTDIR\engine_lib.dll"

    # Supprimer le répertoire d'installation si vide
    RMDir "$INSTDIR"

    # Supprimer le raccourci dans le menu démarrer
    Delete "$SMPROGRAMS\QuantumVortex Engine\QuantumVortex Engine.lnk"
    RMDir "$SMPROGRAMS\QuantumVortex Engine"

SectionEnd