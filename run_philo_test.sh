#!/bin/bash

# Cores para formatação
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
RESET='\033[0m'

# Verifica se a norminette está instalada
check_norminette() {
    if ! command -v norminette &> /dev/null; then
        echo -e "${RED}Norminette não encontrada. Por favor, instale-a antes de continuar.${RESET}"
        exit 1
    fi
    echo -e "${BLUE}Norminette encontrada: $(norminette --version)${RESET}"
}

# Executa a norminette no código
run_norminette() {
    echo -e "\n${PURPLE}=== Verificando conformidade com a Norma 42 ===${RESET}"
    norminette ./src ./includes ./test
    NORM_STATUS=$?

    if [ $NORM_STATUS -eq 0 ]; then
        echo -e "${GREEN}Código está em conformidade com a norma!${RESET}"
    else
        echo -e "${RED}Código NÃO está em conformidade com a norma.${RESET}"
        echo -e "${YELLOW}Por favor, corrija os erros acima antes de continuar.${RESET}"
        exit 1
    fi
}

# Compila o projeto e os testes
compile_project() {
    echo -e "\n${PURPLE}=== Compilando projeto e testes ===${RESET}"
    make fclean
    make test

    if [ $? -ne 0 ]; then
        echo -e "${RED}Erro de compilação. Abortando.${RESET}"
        exit 1
    fi
    echo -e "${GREEN}Compilação bem-sucedida!${RESET}"
}

# Executa os testes
run_tests() {
    echo -e "\n${PURPLE}=== Executando testes ===${RESET}"

    # Define parâmetros padrão ou aceita do usuário
    PHILO_COUNT=${1:-4}
    TIME_TO_DIE=${2:-800}
    TIME_TO_EAT=${3:-200}
    TIME_TO_SLEEP=${4:-200}
    TIMES_TO_EAT=${5:-""}

    # Mostra configuração de teste
    echo -e "${CYAN}Configuração do teste:${RESET}"
    echo -e "Número de filósofos: ${PHILO_COUNT}"
    echo -e "Tempo para morrer: ${TIME_TO_DIE}ms"
    echo -e "Tempo para comer: ${TIME_TO_EAT}ms"
    echo -e "Tempo para dormir: ${TIME_TO_SLEEP}ms"
    if [ -n "$TIMES_TO_EAT" ]; then
        echo -e "Número de vezes que cada filósofo deve comer: ${TIMES_TO_EAT}"
    fi

    # Executa o teste completo
    echo -e "\n${YELLOW}--- Executando teste de filósofos ---${RESET}"
    if [ -n "$TIMES_TO_EAT" ]; then
        ./test $PHILO_COUNT $TIME_TO_DIE $TIME_TO_EAT $TIME_TO_SLEEP $TIMES_TO_EAT
    else
        ./test $PHILO_COUNT $TIME_TO_DIE $TIME_TO_EAT $TIME_TO_SLEEP
    fi
}

# Limpa recursos após testes
cleanup() {
    echo -e "\n${PURPLE}=== Limpando recursos ===${RESET}"
    make clean
    echo -e "${GREEN}Limpeza concluída.${RESET}"
}

# Função principal
main() {
    echo -e "${PURPLE}======================================${RESET}"
    echo -e "${PURPLE}=== Sistema de Testes Philosophers ===${RESET}"
    echo -e "${PURPLE}======================================${RESET}"

    check_norminette
    run_norminette
    compile_project
    run_tests "$@"
    cleanup

    echo -e "\n${GREEN}Todos os testes concluídos!${RESET}"
}

# Executa o script
main "$@"
