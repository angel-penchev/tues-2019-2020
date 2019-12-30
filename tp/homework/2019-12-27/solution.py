class TicTacToeBoard:
    class InvalidMove(Exception):
        pass

    class InvalidValue(Exception):
        pass

    class InvalidKey(Exception):
        pass

    class NotYourTurn(Exception):
        pass

    def __init__(self):
        self.board = {
            'A1': ' ', 'B1': ' ', 'C1': ' ',
            'A2': ' ', 'B2': ' ', 'C2': ' ',
            'A3': ' ', 'B3': ' ', 'C3': ' '}
        self.previous = ' '

    def __getitem__(self, item):
        return self.board[item]

    def __setitem__(self, item, value):
        if item not in self.board.keys():
            raise self.InvalidKey

        if value not in ['O', 'X']:
            raise self.InvalidValue

        if self.board[item] is not ' ':
            raise self.InvalidMove

        if self.previous is value:
            raise self.NotYourTurn

        self.previous = value
        self.board[item] = value

    def __str__(self):
        return '\n  -------------\n' +\
            '3 | {} | {} | {} |\n'.format(self.board['A3'], self.board['B3'], self.board['C3']) +\
            '  -------------\n' +\
            '2 | {} | {} | {} |\n'.format(self.board['A2'], self.board['B2'], self.board['C2']) +\
            '  -------------\n' +\
            '1 | {} | {} | {} |\n'.format(self.board['A1'], self.board['B1'], self.board['C1']) +\
            '  -------------\n' +\
            '    A   B   C  \n'

    def game_status(self):
        b = [[self.board['A3'], self.board['B3'], self.board['C3']],
             [self.board['A2'], self.board['B2'], self.board['C2']],
             [self.board['A1'], self.board['B1'], self.board['C1']]]

        for row in b:
            if row[0] == row[1] == row[2] != ' ':
                return '{} wins!'.format(row[0])

        for col in range(3):
            if b[0][col] == b[1][col] == b[2][col] != ' ':
                return '{} wins!'.format(b[0][col])

        if (b[0][0] == b[1][1] == b[2][2] != ' ') or (b[0][2] == b[1][1] == b[2][0] != ' '):
            return '{} wins!'.format(b[1][1])

        if ' ' in self.board.values():
            return 'Game in progress.'
        else:
            return 'Draw!'
