const EnergyData = require('../models/EnergyData');

exports.getEnergyData = async (req, res) => {
  try {
    const { userId } = req.params;
    const data = await EnergyData.find({ userId });
    res.json(data);
  } catch (error) {
    res.status(500).json({ message: 'Error fetching data' });
  }
};

exports.addEnergyData = async (req, res) => {
  try {
    const { userId, date, energyConsumed } = req.body;
    const newData = new EnergyData({ userId, date, energyConsumed });
    await newData.save();
    res.status(201).json(newData);
  } catch (error) {
    res.status(500).json({ message: 'Error saving data' });
  }
};

exports.predictBill = async (req, res) => {
  // Call Python ML model here.
  res.json({ message: 'Bill prediction logic here' });
};
