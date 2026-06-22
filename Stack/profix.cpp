#include <iostream>
#include <stack>
#include <string>
#include <cctype> // Thư viện chứa hàm isalnum

using namespace std;

// Hàm trả về độ ưu tiên của các toán tử
int getPrecedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; // Trả về 0 cho các ký tự không phải toán tử (ví dụ: dấu ngoặc)
}

// Hàm chính để chuyển đổi Infix sang Postfix
string infixToPostfix(string expression)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        // Bỏ qua các khoảng trắng thừa
        if (c == ' ')
        {
            continue;
        }

        // Trường hợp 1: Nếu là toán hạng (chữ cái hoặc số)
        if (isalnum(c))
        {
            postfix += c;
        }
        // Trường hợp 2: Nếu là dấu ngoặc mở
        else if (c == '(')
        {
            st.push(c);
        }
        // Trường hợp 3: Nếu là dấu ngoặc đóng
        else if (c == ')')
        {
            // Lấy các toán tử ra khỏi stack cho đến khi gặp ngoặc mở
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop(); // Lấy dấu ngoặc mở '(' ra khỏi stack và vứt bỏ
            }
        }
        // Trường hợp 4: Nếu là toán tử (+, -, *, /, ^)
        else
        {
            // Lấy toán tử từ stack ra nếu nó có độ ưu tiên lớn hơn hoặc bằng
            while (!st.empty() && st.top() != '(' && getPrecedence(st.top()) >= getPrecedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            // Đẩy toán tử hiện tại vào stack
            st.push(c);
        }
    }

    // Bước cuối cùng: Lấy tất cả các toán tử còn sót lại trong stack ra
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    // Chạy thử nghiệm
    string bieu_thuc_infix = "A + B * (C - D)";
    string ket_qua_postfix = infixToPostfix(bieu_thuc_infix);

    cout << "Bieu thuc Infix:   " << bieu_thuc_infix << endl;
    cout << "Bieu thuc Postfix: " << ket_qua_postfix << endl;

    return 0;
}