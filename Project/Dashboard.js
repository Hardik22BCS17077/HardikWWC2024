import React from 'react';
import EnergyChart from './EnergyChart';
import BillPrediction from './BillPrediction';

function Dashboard() {
  return (
    <div>
      <h1>Energy Consumption Dashboard</h1>
      <EnergyChart />
      <BillPrediction />
    </div>
  );
}

export default Dashboard;
