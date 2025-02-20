const mongoose = require('mongoose');

const energyDataSchema = new mongoose.Schema({
  userId: String,
  date: Date,
  energyConsumed: Number,
});

module.exports = mongoose.model('EnergyData', energyDataSchema);
