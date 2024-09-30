TODO: make more notes

### Stock Qs
Constraint for all the problem is.. you can't engage in multiple transaction simultaneously

## Q1. Maximize profit with just 1 transaction
M1: Iterate over selling days, buy would be mini so far.

M2: buy/sell FSM state. Iterate and maximize profit after each level

## Q2. Maximize profit with infinite transactions
M1: Go greedy. Sell whenever price increases.

M2: buy/sell state. Model Q as dp[lev][state] = max profit for being in 'state' after [0...lev] stock

## Q3. Two transactions allowed
Sol: Model DP as what transaction you're doing atm and in which state

FSM States: 0th buy, 0th sell, 1st buy, 1st sell
Could solve with just 4 variables, dp array ki jarurat nahi

## Q4. k transactions allowed
M1: O(nk) space. dp[lev][k] _/		O(kn^2) T.C worst case

M2: dp[k][state]	States are buy(0) / sell(1)

Visualize FSM diagram (linear here)

dp[k][0] = max profit for buying stock at kth transaction \
dp[k][1] = max profit for selling stock at kth transaction

## Q5. Infinite transactions with cooldown
M1: dp[lev] O(n^2) T.C.

M2: FSM. Buy / Sell / Rest states	(rest is due to cooldown) \
Draw FSM, and model dp as dp[lev][state] = max profit after lev to be in 'state'

## Q6 Infinite transaction with transac fee
Sol: Same as Q2 infinite transactions, but add a fee to buying costs \
Model as dp[lev][state] , cut fee whenever u buy