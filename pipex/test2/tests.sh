#!/bin/bash

# Fonction pour exécuter les tests avec pipex
run_pipex_tests() {
    echo "Running tests with pipex..."

    # Test 1: Infile inexistant
    echo -e "\nTest 1: Infile inexistant"
    .././pipex nonexistent_file "ls -la" cat test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    echo "------------------------"

    # Test 2: Cmd1 inexistant
    echo -e "\nTest 2: Cmd1 inexistant"
    .././pipex test_infile "lsdvs -la" cat test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    echo "------------------------"

    # Test 3: Cmd1 valide, Cmd2 valide
    echo -e "\nTest 3: Cmd1 et Cmd2 valides"
    .././pipex test_infile "ls -la" cat test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    echo "------------------------"

    # Test 4: Cmd2 inexistant
    echo -e "\nTest 4: Cmd2 inexistant"
    .././pipex test_infile "ls -la" lsdvs test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    echo "------------------------"

    # Test 5: Permissions d'écriture refusées pour outfile
    echo -e "\nTest 5: Permissions d'écriture refusées pour outfile"
    chmod 000 test_outfile
    .././pipex test_infile "ls -la" cat test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    chmod 777 test_outfile
    echo "------------------------"

    # Test 6: Permissions de lecture refusées pour infile
    echo -e "\nTest 6: Permissions de lecture refusées pour infile"
    touch readonly_infile
    chmod 000 readonly_infile
    .././pipex readonly_infile "ls -la" cat test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    chmod 777 readonly_infile
    rm readonly_infile
    echo "------------------------"

    # Test 7: Cmd1 sans permissions d'exécution
    echo -e "\nTest 7: Cmd1 sans permissions d'exécution"
    touch no_exec_cmd
    chmod 000 no_exec_cmd
    .././pipex test_infile "./no_exec_cmd" cat test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    rm no_exec_cmd
    echo "------------------------"

    # Test 8: Cmd2 sans permissions d'exécution
    echo -e "\nTest 8: Cmd2 sans permissions d'exécution"
    touch no_exec_cmd
    chmod 000 no_exec_cmd
    .././pipex test_infile "ls -la" "./no_exec_cmd" test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    rm no_exec_cmd
    echo "------------------------"

    # Test 9: Infile vide
    echo -e "\nTest 9: Infile vide"
    touch empty_infile
    .././pipex empty_infile "ls -la" cat test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    rm empty_infile
    echo "------------------------"

    # Test 10: Outfile existant
    echo -e "\nTest 10: Outfile existant"
    echo "Existing content" > test_outfile
    .././pipex test_infile "ls -la" cat test_outfile 2> pipex_err.log
    echo "Pipex stderr:"
    cat pipex_err.log
    echo "Exit status: $?"
    echo "------------------------"
}

# Fonction pour exécuter les tests avec bash
run_bash_tests() {
    echo "Running tests with bash..."

    # Test 1: Infile inexistant
    echo -e "\nTest 1: Infile inexistant"
    < nonexistent_file ls -la | cat > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    echo "------------------------"

    # Test 2: Cmd1 inexistant
    echo -e "\nTest 2: Cmd1 inexistant"
    < test_infile lsdvs -la | cat > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    echo "------------------------"

    # Test 3: Cmd1 valide, Cmd2 valide
    echo -e "\nTest 3: Cmd1 et Cmd2 valides"
    < test_infile ls -la | cat > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    echo "------------------------"

    # Test 4: Cmd2 inexistant
    echo -e "\nTest 4: Cmd2 inexistant"
    < test_infile ls -la | lsdvs > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    echo "------------------------"

    # Test 5: Permissions d'écriture refusées pour outfile
    echo -e "\nTest 5: Permissions d'écriture refusées pour outfile"
    chmod 000 test_outfile
    < test_infile ls -la | cat > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    chmod 777 test_outfile
    echo "------------------------"

    # Test 6: Permissions de lecture refusées pour infile
    echo -e "\nTest 6: Permissions de lecture refusées pour infile"
    touch readonly_infile
    chmod 000 readonly_infile
    < readonly_infile ls -la | cat > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    chmod 777 readonly_infile
    rm readonly_infile
    echo "------------------------"

    # Test 7: Cmd1 sans permissions d'exécution
    echo -e "\nTest 7: Cmd1 sans permissions d'exécution"
    touch no_exec_cmd
    chmod 000 no_exec_cmd
    < test_infile ./no_exec_cmd | cat > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    rm no_exec_cmd
    echo "------------------------"

    # Test 8: Cmd2 sans permissions d'exécution
    echo -e "\nTest 8: Cmd2 sans permissions d'exécution"
    touch no_exec_cmd
    chmod 000 no_exec_cmd
    < test_infile ls -la | ./no_exec_cmd > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    rm no_exec_cmd
    echo "------------------------"

    # Test 9: Infile vide
    echo -e "\nTest 9: Infile vide"
    touch empty_infile
    < empty_infile ls -la | cat > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    rm empty_infile
    echo "------------------------"

    # Test 10: Outfile existant
    echo -e "\nTest 10: Outfile existant"
    echo "Existing content" > test_outfile
    < test_infile ls -la | cat > test_outfile 2> bash_err.log
    echo "Bash stderr:"
    cat bash_err.log
    echo "Exit status: $?"
    echo "------------------------"
}

# Préparer les fichiers de test
touch test_infile
echo "Test content" > test_infile
touch test_outfile
chmod 777 test_outfile

# Exécuter les tests avec pipex
run_pipex_tests

# Nettoyer les fichiers de test
rm -f test_infile test_outfile

# Préparer les fichiers de test à nouveau
touch test_infile
echo "Test content" > test_infile
touch test_outfile
chmod 777 test_outfile

# Exécuter les tests avec bash
run_bash_tests

# Nettoyer les fichiers de test
rm -f test_infile test_outfile
