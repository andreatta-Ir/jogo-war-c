# Jogo War em C

Uma implementação simplificada do jogo de tabuleiro War (Risk-like) em linguagem C. Usa conceitos avançados como structs, ponteiros, alocação dinâmica de memória (`malloc`/`free`), strings (`strcpy`/`strcmp`), loops e funções modulares.

## Funcionalidades
- **Cadastro de Territórios**: Atualize nome, cor (jogador), número de tropas e continente via ID.
- **Exibição de Territórios**: Lista todos os 10 territórios iniciais (Ásia, América do Sul, América do Norte e Europa).
- **Simulação de Ataques**: Ataque entre territórios com mecânica aleatória (baseada em `rand()`). Regras: Pelo menos 2 tropas no atacante; não ataca aliados. Vencedor conquista o território.
- **Verificação de Vitória**: Missão estratégica – conquiste todos os territórios da Ásia (4) **e** América do Sul (3) com a cor do jogador para vencer.

Territórios iniciais (todos "neutro"):
- Ásia: China (5 tropas), India (4), Japao (3), Coreia (2).
- América do Sul: Brasil (4), Argentina (3), Venezuela (2).
- Outros: EUA (6), Mexico (3), Russia (5).

## Como Compilar e Executar
1. Instale GCC (compilador C): No Linux/macOS: `sudo apt install gcc` ou `brew install gcc`. No Windows: MinGW ou Visual Studio Code com extensão C.
2. No terminal/prompt, navegue até a pasta do projeto: `cd caminho/para/projeto`.
3. Compile: `gcc war.c -o war` (Linux/macOS) ou `gcc war.c -o war.exe` (Windows).
4. Execute: `./war` (Linux/macOS) ou `war.exe` (Windows).
5. Use o menu interativo:
   - 1: Exibir territórios.
   - 2: Atualizar território (ex: ID 0 para China).
   - 3: Ataque (ex: ID 0 ataca ID 4).
   - 4: Verificar vitória (ex: cor "vermelho").
   - 5: Sair.

## Exemplo de Saída
