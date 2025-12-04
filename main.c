#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	int ret;

	ret = printf("%5.3d", 11);
    printf("\n%d", ret);
    return (0);
}

// void    check_case(char *desc, int ret_ft, int ret_orig)
// {
//     if (ret_ft == ret_orig)
//         printf("\n✅ [OK] %s -> Ret : %d\n", desc, ret_ft);
//     else
//         printf("\n❌ [KO] %s -> FT=%d | ORIG=%d\n", desc, ret_ft, ret_orig);
//     printf("--------------------------------------------\n");
// }

// int main(void)
// {
//     int ret_ft;
//     int ret_orig;
//     int a = 42;
//     int *ptr = &a;
//     char *str_null = NULL; 
//     void *ptr_null = NULL;
//     printf("\n===== DEBUT DES TESTS FT_PRINTF =====\n\n");
//     // --- TEST 1 : Caractères simples (%c) ---
//     printf("--- TEST 1 : Caractères (%%c) ---\n");
//     printf("[FT]   : ");
//     ret_ft = ft_printf("Char: %c\n", 'A');
//     printf("[ORIG] : ");
//     ret_orig = printf("Char: %c\n", 'A');
//     check_case("Char simple", ret_ft, ret_orig);
//     // --- TEST 2 : Chaînes de caractères (%s) ---
//     printf("--- TEST 2 : Strings (%%s) ---\n");
//     printf("[FT]   : ");
//     ret_ft = ft_printf("String: %s\n", "Bonjour 42");
//     printf("[ORIG] : ");
//     ret_orig = printf("String: %s\n", "Bonjour 42");
//     check_case("String simple", ret_ft, ret_orig);
//     // ATTENTION : Sur Linux, le printf original peut CRASH ici (Segfault).
//     // Sur Mac/Moulinette, il affiche "(null)".
//     printf("[FT]   : ");
//     ret_ft = ft_printf("NULL String: %s\n", str_null);
//     printf("[ORIG] : ");
//     ret_orig = printf("NULL String: %s\n", str_null);
//     check_case("String NULL", ret_ft, ret_orig);
//     // --- TEST 3 : Entiers décimaux (%d, %i) ---
//     printf("--- TEST 3 : Entiers (%%d, %%i) ---\n");
//     printf("[FT]   : ");
//     ret_ft = ft_printf("Int: %d | Neg: %i\n", 42, -42);
//     printf("[ORIG] : ");
//     ret_orig = printf("Int: %d | Neg: %i\n", 42, -42);
//     check_case("Entiers basiques", ret_ft, ret_orig);
//     printf("[FT]   : ");
//     ret_ft = ft_printf("INT_MAX: %d | INT_MIN: %d\n", INT_MAX, INT_MIN);
//     printf("[ORIG] : ");
//     ret_orig = printf("INT_MAX: %d | INT_MIN: %d\n", INT_MAX, INT_MIN);
//     check_case("Limites Int", ret_ft, ret_orig);
//     // --- TEST 4 : Non signés (%u) ---
//     printf("--- TEST 4 : Unsigned (%%u) ---\n");
//     printf("[FT]   : ");
//     ret_ft = ft_printf("Unsigned: %u\n", 4294967295u);
//     printf("[ORIG] : ");
//     ret_orig = printf("Unsigned: %u\n", 4294967295u);
//     check_case("Unsigned Max", ret_ft, ret_orig);
//     // --- TEST 5 : Hexadécimal (%x, %X) ---
//     printf("--- TEST 5 : Hexa (%%x, %%X) ---\n");
//     printf("[FT]   : ");
//     ret_ft = ft_printf("Hex bas: %x | Hex haut: %X\n", 255, 255);
//     printf("[ORIG] : ");
//     ret_orig = printf("Hex bas: %x | Hex haut: %X\n", 255, 255);
//     check_case("Hex simple", ret_ft, ret_orig);
//     printf("[FT]   : ");
//     ret_ft = ft_printf("Zero: %x\n", 0);
//     printf("[ORIG] : ");
//     ret_orig = printf("Zero: %x\n", 0);
//     check_case("Hex Zero", ret_ft, ret_orig);
//     // --- TEST 6 : Pointeurs (%p) ---
//     printf("--- TEST 6 : Pointeurs (%%p) ---\n");
//     printf("[FT]   : ");
//     ret_ft = ft_printf("Ptr: %p\n", ptr);
//     printf("[ORIG] : ");
//     ret_orig = printf("Ptr: %p\n", ptr);
//     check_case("Pointeur valide", ret_ft, ret_orig);
//     printf("[FT]   : ");
//     ret_ft = ft_printf("Ptr NULL: %p\n", ptr_null);
//     printf("[ORIG] : ");
//     ret_orig = printf("Ptr NULL: %p\n", ptr_null);
//     check_case("Pointeur NULL", ret_ft, ret_orig);
//     // --- TEST 7 : Pourcentage (%%) ---
//     printf("--- TEST 7 : Pourcentage (%%%%) ---\n");
//     printf("[FT]   : ");
//     ret_ft = ft_printf("100%%\n");
//     printf("[ORIG] : ");
//     ret_orig = printf("100%%\n");
//     check_case("Double pourcent", ret_ft, ret_orig);
//     return (0);
// }
