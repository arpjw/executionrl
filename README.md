# executionrl 

**executiorl** is a high-level C++ simulator that models **optimal trade execution** using **reinforcement learning**. it uses a q-learning agent trained in a simulated market environment to decide when to buy, sell, or hold in order to minimize execution cost and maximize reward.

---

## project structure
```bash
executionrl/
├── include/
│ ├── agents/ # qlearningagent logic
│ ├── core/ # executionsimulator
│ ├── env/ # market environment simulator
│ ├── utils/ # logger, math, config
├── src/ # main.cpp entry point
├── data/ # price_series.csv (input data)
├── results/ # outputs, logs, and plots
├── tests/ # test_agent, test_env, test_simulation
├── cmakelists.txt
```

---

## how it works

the simulator trains an agent to optimally execute trades by interacting with a synthetic market. the agent receives state observations (price movement, position, time) and learns a policy using q-learning.

### agent: `qlearningagent`

- discrete action space: `buy`, `sell`, `hold`
- updates q-values with:
```bash
  - Q(s,a) ← Q(s,a) + α [r + γ max Q(s',a') - Q(s,a)]
```
### environment: `marketenvironment`

- steps through a price series
- responds to actions with:
  - execution results
  - position tracking
  - reward feedback

### simulator: `executionsimulator`

- runs multiple episodes of training
- manages state transitions and learning updates

---

## build instructions

```bash
mkdir build && cd build
cmake ..
make
```

## run tests
make sure to build tests via cmake (already configured):
```bash
./test_agent
./test_env
./test_simulation
```
or run all using:
```bash
ctest
```

---

## sample output
trained agent over 1000 episodes:
```bash
episode 1: total reward = -21.5
episode 500: total reward = +3.7
episode 1000: total reward = +8.2
```
