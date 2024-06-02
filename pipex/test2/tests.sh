#!/bin/bash

# Fonctions pour afficher les messages de test
print_success() {
    echo -e "\033[0;32m[SUCCESS]\033[0m $1"
}

print_failure() {
    echo -e "\033[0;31m[FAILURE]\033[0m $1"
}

# Créer des fichiers de test
echo "Creating test files..."
echo -e "Hello\nWorld\n42\nSchool" > infile
echo -e "42" > expected1
echo -e "Hello World 42 School" > expected2
echo -e "Hello\nWorld\n42\nSchool" > expected3
echo -e "4" > expected4
echo -e "School" > expected5
echo -e "HELLO\nWORLD\n42\nSCHOOL" > expected6
echo -e "1" > expected7
echo -e "Hello" > expected8
echo -e "Hello" > expected9
echo -e "School" > expected10

# Lancer les tests
echo "Running tests..."

# Test 1: Commande grep 42 | cat
./pipex infile "grep 42" "cat" outfile
diff -q outfile expected1
if [ $? -eq 0 ]; then
    print_success "Test 1 passed"
else
    print_failure "Test 1 failed"
fi

# Test 2: Commande tr '\n' ' ' | cat
./pipex infile "tr '\n' ' '" "cat" outfile
diff -q outfile expected2
if [ $? -eq 0 ]; then
    print_success "Test 2 passed"
else
    print_failure "Test 2 failed"
fi

# Test 3: Commande cat | cat
./pipex infile "cat" "cat" outfile
diff -q outfile expected3
if [ $? -eq 0 ]; then
    print_success "Test 3 passed"
else
    print_failure "Test 3 failed"
fi

# Test 4: Commande cat | wc -l
./pipex infile "cat" "wc -l" outfile
diff -q outfile expected4
if [ $? -eq 0 ]; then
    print_success "Test 4 passed"
else
    print_failure "Test 4 failed"
fi

# Test 5: Commande cat | tail -1
./pipex infile "cat" "tail -1" outfile
diff -q outfile expected5
if [ $? -eq 0 ]; then
    print_success "Test 5 passed"
else
    print_failure "Test 5 failed"
fi

# Test 6: Commande tr a-z A-Z | cat
./pipex infile "tr a-z A-Z" "cat" outfile
diff -q outfile expected6
if [ $? -eq 0 ]; then
    print_success "Test 6 passed"
else
    print_failure "Test 6 failed"
fi

# Test 7: Commande grep 42 | wc -l
./pipex infile "grep 42" "wc -l" outfile
diff -q outfile expected7
if [ $? -eq 0 ]; then
    print_success "Test 7 passed"
else
    print_failure "Test 7 failed"
fi

# Test 8: Commande head -1 | cat
./pipex infile "head -1" "cat" outfile
diff -q outfile expected8
if [ $? -eq 0 ]; then
    print_success "Test 8 passed"
else
    print_failure "Test 8 failed"
fi

# Test 9: Commande grep Hello | head -1
./pipex infile "grep Hello" "head -1" outfile
diff -q outfile expected9
if [ $? -eq 0 ]; then
    print_success "Test 9 passed"
else
    print_failure "Test 9 failed"
fi

# Test 10: Commande tail -1 | cat
./pipex infile "tail -1" "cat" outfile
diff -q outfile expected10
if [ $? -eq 0 ]; then
    print_success "Test 10 passed"
else
    print_failure "Test 10 failed"
fi

# Nettoyer les fichiers créés
echo "Cleaning up..."
rm -f infile expected1 expected2 expected3 expected4 expected5 expected6 expected7 expected8 expected9 expected10 outfile

echo "Done."
