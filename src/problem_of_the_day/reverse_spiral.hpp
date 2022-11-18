class ReverseSpiral
{
    public:
    enum class direction_e
    {
        RIGHT_E = 0,
        DOWN_E,
        LEFT_E,
        UP_E,
    };

    static direction_e get_next_direction(direction_e e_direction);

    static bool can_go_forward(direction_e e_direction, int row_idx, int row_len, int col_idx, int col_len, std::vector<std::vector<bool>> &not_visited);

    static void move_forward(direction_e e_direction, int &row_idx, int &col_idx);

    static direction_e next_direction(direction_e e_direction);
};
