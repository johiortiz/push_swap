#!/usr/bin/env python3
import random
import subprocess
import sys
from statistics import mean

def generate_random_numbers(n):
    numbers = list(range(1, n + 1))
    random.shuffle(numbers)
    return numbers

def test_push_swap(numbers):
    numbers_str = ' '.join(map(str, numbers))
    try:
        # Ejecutar push_swap y contar las operaciones
        result = subprocess.run(['./push_swap'] + numbers_str.split(), 
                              capture_output=True, text=True)
        operations = result.stdout.count('\n')
        
        # Verificar si está ordenado usando checker
        checker = subprocess.run(['./checker_linux'] + numbers_str.split(),
                               input=result.stdout,
                               capture_output=True,
                               text=True)
        is_sorted = checker.stdout.strip() == 'OK'
        
        return operations, is_sorted
    except subprocess.CalledProcessError as e:
        print(f"Error ejecutando push_swap: {e}")
        return -1, False

def run_tests(size, num_tests=100):
    results = []
    for i in range(num_tests):
        numbers = generate_random_numbers(size)
        operations, is_sorted = test_push_swap(numbers)
        if operations >= 0 and is_sorted:
            results.append(operations)
        if not is_sorted:
            print(f"Error: No se ordenó correctamente para n={size}, test {i+1}")
            print("Números:", ' '.join(map(str, numbers)))
            return None
    return results

def main():
    test_sizes = [3, 4, 5, 10, 100, 500]
    print("\nPruebas de Push_swap:")
    print("=" * 50)
    
    for size in test_sizes:
        print(f"\nProbando con {size} números:")
        results = run_tests(size, 100 if size <= 100 else 10)
        if results:
            avg = mean(results)
            min_ops = min(results)
            max_ops = max(results)
            print(f"  Promedio de operaciones: {avg:.2f}")
            print(f"  Mínimo de operaciones: {min_ops}")
            print(f"  Máximo de operaciones: {max_ops}")
        else:
            print("  ❌ Falló las pruebas")

if __name__ == "__main__":
    main() 