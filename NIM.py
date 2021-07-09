def computador_escolhe_jogada(n, m):
    jogada = m
    while jogada <= m and jogada > 0:    
        if (n - jogada)%(m+1) == 0:
            return jogada
        else:
            jogada = jogada - 1

def usuario_escolhe_jogada(n, m):
    jogada = int(input("Quantas peças você vai tirar? "))
    while jogada > m or jogada <= 0:
        print("Oops! Jogada inválida! Tente de novo.")
        jogada = int(input("Quantas peças você vai tirar? "))       
    return jogada
    
def partida():
    n = int(input("Quantas peças? "))
    m = int(input("Limite de peças por jogada? "))
    if n%(m+1) == 0:
        print("Voce começa!")
        while n > 0:
            jogadaU = usuario_escolhe_jogada(n, m)
            print("Você tirou", jogadaU, "peças.")
            n = n - jogadaU
            print("Agora restam", n, "peças no tabuleiro.")
            if n == 0:
                print("Fim de jogo! Você ganhou!")
                return "U"
            else:
                jogadaC = computador_escolhe_jogada(n, m)
                print("O computador tirou", jogadaC, "peças.")
                n = n - jogadaC
                print("Agora restam", n, "peças no tabuleiro.")
                if n == 0:
                    print("Fim de Jogo! O computador ganhou!")
                    return "C"
    else:
        print("Computador começa!")
        while n > 0:
            jogadaC = computador_escolhe_jogada(n, m)
            print("O computador tirou", jogadaC, "peças.")
            n = n - jogadaC
            print("Agora restam", n, "peças no tabuleiro.")
            if n == 0:
                print("Fim de jogo! O computador ganhou!")
                return "C"
            else:
                jogadaU = usuario_escolhe_jogada(n, m)
                print("Você tirou", jogadaU, "peças.")
                n = n - jogadaU
                print("Agora restam", n, "peças no tabuleiro.")
                if n == 0:
                    print("Fim de jogo! Você ganhou!")
                    return "U"
                
def campeonato():
    print("Você escolheu um campeonato!")
    pu = 0
    pc = 0
    print("*** Rodada 1***")
    placar1 = partida()
    if placar1 == "C":
        pc = pc + 1
    if placar1 == "U":
        pu = pu + 1
    print("*** Rodada 2***")
    placar2 = partida()
    if placar2 == "C":
        pc = pc + 1
    if placar2 == "U":
        pu = pu + 1
    print("*** Rodada 3***")
    placar3 = partida()
    if placar3 == "C":
        pc = pc + 1
    if placar3 == "U":
        pu = pu + 1
    print("Placar: Você:", pu, "X", pc, "Computador")    
    
def main():
    print("Bem-vindo ao jogo NIM! Escolha: ")
    print("1 - para jogar uma partida isolada")
    print("2 - para jogar um campeonato")

    escolha = input("Opção: ")

    if escolha == "1":
        partida()
    if escolha == "2":
        campeonato()
    if escolha != "1" and escolha != "2":
        print("Opção inválida!")
        main()

main()

    



